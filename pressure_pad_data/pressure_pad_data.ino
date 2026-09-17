/* ═══════════════════════════════════════════════════════════════════════════
   PRESSURE PAD — WiFi scanning firmware
   Arduino GIGA R1 WiFi + 8x ADS1115 across two I2C buses

   Streams each scanned row as one UDP packet over the local network.
   Serial output is kept as a fallback for bench debugging.
   ═══════════════════════════════════════════════════════════════════════════ */

#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <WiFi.h>
#include <WiFiUdp.h>

// ── WIFI CONFIGURATION ─────────────────────────────────────────────────────
// SSID/password of the GL.iNet router, NOT the hospital network.
const char* WIFI_SSID = "Tatonetti Lab";
const char* WIFI_PASS = "Tatonetti";

// Broadcast mode means the laptop does not need a fixed IP — it just listens.
// Set to 0 and fill in targetIP to send to one specific machine instead.
#define USE_BROADCAST 1
IPAddress targetIP(192, 168, 8, 100);   // only used when USE_BROADCAST is 0

const uint16_t UDP_PORT = 4210;

// ── CONFIGURATION ──────────────────────────────────────────────────────────
// To add more columns/rows, increment NUM_COLS/NUM_ROWS

#define NUM_COLS     12
#define NUM_ROWS     5

#define SERIAL_DEBUG 1    // 1 = also print the grid to Serial, 0 = UDP only
#define FRAME_DELAY  100  // ms between full scans

// ── CHIP DEFINITIONS ───────────────────────────────────────────────────────
// Board 1: Cols 1-4 (Wire, 0x48 [GND]) + Cols 5-8 (Wire2, 0x48 [GND])      [DONE]
// Board 2: Cols 9-12 (Wire, 0x49 [VDD]) + Cols 13-16 (Wire2, 0x49 [VDD])   [90%]
// Board 3: Cols 17-20 (Wire, 0x4A [SDA]) + Cols 21-24 (Wire2, 0x4A [SDA])  [90%]
// Board 4: Cols 25-28 (Wire, 0x4B [SCL]) + Cols 29-32 (Wire2, 0x4B [SCL])  [90%]

// ── ARDUINO I2C PIN ASSIGNMENTS ────────────────────────────────────────────
// Wire  (I2C bus 1): SDA = pin 20, SCL = pin 21
// Wire2 (I2C bus 2): SDA = pin 9,  SCL = pin 8

Adafruit_ADS1115 ads_w1;   // Wire,  0x48 — Cols 1-4
Adafruit_ADS1115 ads_w1_2; // Wire2, 0x48 — Cols 5-8
#if NUM_COLS >= 12
Adafruit_ADS1115 ads_w2;   // Wire,  0x49 — Cols 9-12
#endif
#if NUM_COLS >= 16
Adafruit_ADS1115 ads_w2_2; // Wire2, 0x49 — Cols 13-16
#endif
#if NUM_COLS >= 20
Adafruit_ADS1115 ads_w3;   // Wire,  0x4A — Cols 17-20
#endif
#if NUM_COLS >= 24
Adafruit_ADS1115 ads_w2_3; // Wire2, 0x4A — Cols 21-24
#endif
#if NUM_COLS >= 28
Adafruit_ADS1115 ads_w4;   // Wire,  0x4B — Cols 25-28
#endif
#if NUM_COLS >= 32
Adafruit_ADS1115 ads_w2_4; // Wire2, 0x4B — Cols 29-32
#endif

// ── ROW PINS ───────────────────────────────────────────────────────────────
// Add more pins here as rows are added (up to 24 for full pad)
const int rowPins[NUM_ROWS] = {2, 3, 4, 5, 6};

// ── STORAGE ────────────────────────────────────────────────────────────────
float readings[NUM_ROWS][NUM_COLS];

// ── NETWORK STATE ──────────────────────────────────────────────────────────
WiFiUDP    udp;
IPAddress  destIP;                 // resolved once WiFi is up
bool       netReady    = false;
uint32_t   frameId     = 0;
uint32_t   lastScanMs  = 0;        // measured duration of the last full scan

// Packet buffer. Worst case is 32 cols x 7 chars + header + margin.
char packet[320];

// ── WIFI CONNECT ───────────────────────────────────────────────────────────
// Returns true if associated. Non-fatal: the pad still scans and prints to
// Serial if the network is down, so a dropped router does not stop the device.
bool connectWiFi(uint32_t timeoutMs = 20000) {
  Serial.print("WiFi: connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  uint32_t start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < timeoutMs) {
    delay(400);
    Serial.print(".");
  }
  Serial.println();

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi: FAILED — continuing on Serial only");
    return false;
  }

  IPAddress ip = WiFi.localIP();
  Serial.print("WiFi: connected, GIGA IP = ");
  Serial.println(ip);
  Serial.print("WiFi: signal ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");

#if USE_BROADCAST
  // Subnet broadcast (e.g. 192.168.8.255) is more reliably routed than
  // 255.255.255.255 on many stacks.
  destIP = ip;
  destIP[3] = 255;
#else
  destIP = targetIP;
#endif

  udp.begin(UDP_PORT);
  Serial.print("UDP: streaming to ");
  Serial.print(destIP);
  Serial.print(":");
  Serial.println(UDP_PORT);
  return true;
}

// ── UDP HELPERS ────────────────────────────────────────────────────────────
void sendPacket(const char* buf) {
  if (!netReady) return;
  udp.beginPacket(destIP, UDP_PORT);
  udp.write((const uint8_t*)buf, strlen(buf));
  udp.endPacket();
}

// Frame start marker — tells the receiver the grid shape and frame number, so
// it can allocate correctly and detect dropped rows.
// Format:  FRAME,<frameId>,<rows>,<cols>,<lastScanMs>
void sendFrameStart() {
  snprintf(packet, sizeof(packet), "FRAME,%lu,%d,%d,%lu",
           (unsigned long)frameId, NUM_ROWS, NUM_COLS,
           (unsigned long)lastScanMs);
  sendPacket(packet);
}

// One row per packet, keeping every payload well under the MTU.
// Format:  ROW,<frameId>,<rowIndex>,v0,v1,...,vN
void sendRow(int row) {
  if (!netReady) return;

  int n = snprintf(packet, sizeof(packet), "ROW,%lu,%d",
                   (unsigned long)frameId, row);

  for (int col = 0; col < NUM_COLS; col++) {
    // 3 decimals is ~1 mV of resolution — well below the sensor's noise floor,
    // and it keeps the packet small.
    n += snprintf(packet + n, sizeof(packet) - n, ",%.3f", readings[row][col]);
    if (n >= (int)sizeof(packet) - 8) break;   // guard against overflow
  }
  sendPacket(packet);
}

// Frame end marker — receiver can render as soon as it sees this.
void sendFrameEnd() {
  snprintf(packet, sizeof(packet), "END,%lu", (unsigned long)frameId);
  sendPacket(packet);
}

// ── SETUP ──────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(2000); // Give serial monitor time to connect
  Serial.println("Starting...");

  Wire.begin();
  Serial.println("Wire initialized");

  Wire2.begin();
  Serial.println("Wire2 initialized");

  if (!ads_w1.begin(0x48, &Wire)) {
    Serial.println("ERROR: Board1 Wire chip not found");
    while (1);
  }
  Serial.println("Board1 Wire OK");

  if (!ads_w1_2.begin(0x48, &Wire2)) {
    Serial.println("ERROR: Board1 Wire2 chip not found");
    while (1);
  }
  Serial.println("Board1 Wire2 OK");

  #if NUM_COLS >= 12
    if (!ads_w2.begin(0x49, &Wire)) {
      Serial.println("ERROR: Board2 Wire chip not found");
      while (1);
    }
    Serial.println("Board2 Wire OK");
  #endif

  for (int i = 0; i < NUM_ROWS; i++) {
    pinMode(rowPins[i], INPUT);
  }

  // Network comes up last so an ADC fault is reported before any WiFi delay.
  netReady = connectWiFi();

  Serial.println("Setup complete");
}

// ── READ ONE ROW ───────────────────────────────────────────────────────────
void readRow(int row) {
  // Set all rows high impedance
  for (int i = 0; i < NUM_ROWS; i++) {
    pinMode(rowPins[i], INPUT);
  }

  // Drive selected row HIGH
  pinMode(rowPins[row], OUTPUT);
  digitalWrite(rowPins[row], HIGH);
  delayMicroseconds(100);

  // Chip 1 — Wire, 0x48 — Cols 1-4
  readings[row][0] = ads_w1.computeVolts(ads_w1.readADC_SingleEnded(0));
  readings[row][1] = ads_w1.computeVolts(ads_w1.readADC_SingleEnded(1));
  readings[row][2] = ads_w1.computeVolts(ads_w1.readADC_SingleEnded(2));
  readings[row][3] = ads_w1.computeVolts(ads_w1.readADC_SingleEnded(3));

#if NUM_COLS >= 8
  // Chip 2 — Wire2, 0x48 — Cols 5-8
  readings[row][4] = ads_w1_2.computeVolts(ads_w1_2.readADC_SingleEnded(0));
  readings[row][5] = ads_w1_2.computeVolts(ads_w1_2.readADC_SingleEnded(1));
  readings[row][6] = ads_w1_2.computeVolts(ads_w1_2.readADC_SingleEnded(2));
  readings[row][7] = ads_w1_2.computeVolts(ads_w1_2.readADC_SingleEnded(3));
#endif

#if NUM_COLS >= 12
  // Chip 3 — Wire, 0x49 — Cols 9-12
  readings[row][8]  = ads_w2.computeVolts(ads_w2.readADC_SingleEnded(0));
  readings[row][9]  = ads_w2.computeVolts(ads_w2.readADC_SingleEnded(1));
  readings[row][10] = ads_w2.computeVolts(ads_w2.readADC_SingleEnded(2));
  readings[row][11] = ads_w2.computeVolts(ads_w2.readADC_SingleEnded(3));
#endif

#if NUM_COLS >= 16
  // Chip 4 — Wire2, 0x49 — Cols 13-16
  readings[row][12] = ads_w2_2.computeVolts(ads_w2_2.readADC_SingleEnded(0));
  readings[row][13] = ads_w2_2.computeVolts(ads_w2_2.readADC_SingleEnded(1));
  readings[row][14] = ads_w2_2.computeVolts(ads_w2_2.readADC_SingleEnded(2));
  readings[row][15] = ads_w2_2.computeVolts(ads_w2_2.readADC_SingleEnded(3));
#endif

#if NUM_COLS >= 20
  // Chip 5 — Wire, 0x4A — Cols 17-20
  readings[row][16] = ads_w3.computeVolts(ads_w3.readADC_SingleEnded(0));
  readings[row][17] = ads_w3.computeVolts(ads_w3.readADC_SingleEnded(1));
  readings[row][18] = ads_w3.computeVolts(ads_w3.readADC_SingleEnded(2));
  readings[row][19] = ads_w3.computeVolts(ads_w3.readADC_SingleEnded(3));
#endif

#if NUM_COLS >= 24
  // Chip 6 — Wire2, 0x4A — Cols 21-24
  readings[row][20] = ads_w2_3.computeVolts(ads_w2_3.readADC_SingleEnded(0));
  readings[row][21] = ads_w2_3.computeVolts(ads_w2_3.readADC_SingleEnded(1));
  readings[row][22] = ads_w2_3.computeVolts(ads_w2_3.readADC_SingleEnded(2));
  readings[row][23] = ads_w2_3.computeVolts(ads_w2_3.readADC_SingleEnded(3));
#endif

#if NUM_COLS >= 28
  // Chip 7 — Wire, 0x4B — Cols 25-28
  readings[row][24] = ads_w4.computeVolts(ads_w4.readADC_SingleEnded(0));
  readings[row][25] = ads_w4.computeVolts(ads_w4.readADC_SingleEnded(1));
  readings[row][26] = ads_w4.computeVolts(ads_w4.readADC_SingleEnded(2));
  readings[row][27] = ads_w4.computeVolts(ads_w4.readADC_SingleEnded(3));
#endif

#if NUM_COLS >= 32
  // Chip 8 — Wire2, 0x4B — Cols 29-32
  readings[row][28] = ads_w2_4.computeVolts(ads_w2_4.readADC_SingleEnded(0));
  readings[row][29] = ads_w2_4.computeVolts(ads_w2_4.readADC_SingleEnded(1));
  readings[row][30] = ads_w2_4.computeVolts(ads_w2_4.readADC_SingleEnded(2));
  readings[row][31] = ads_w2_4.computeVolts(ads_w2_4.readADC_SingleEnded(3));
#endif

  // Return row to high impedance
  pinMode(rowPins[row], INPUT);
}

// ── SERIAL OUTPUT (fallback / bench debugging) ─────────────────────────────
#if SERIAL_DEBUG
void printHeader() {
  Serial.print("\t\t");
  for (int col = 0; col < NUM_COLS; col++) {
    Serial.print("Col ");
    Serial.print(col + 1);
    Serial.print("\t\t");
  }
  Serial.println();
  Serial.println("------------------------------------------------------------------------");
}

void printGrid() {
  printHeader();
  for (int row = 0; row < NUM_ROWS; row++) {
    Serial.print("Row "); Serial.print(row + 1); Serial.print(":\t\t");
    for (int col = 0; col < NUM_COLS; col++) {
      Serial.print(readings[row][col], 4);
      Serial.print("V\t\t");
    }
    Serial.println();
  }
  Serial.println("------------------------------------------------------------------------");
  Serial.print("Scan time: "); Serial.print(lastScanMs); Serial.println(" ms");
  Serial.println();
}
#endif

// ── LOOP ───────────────────────────────────────────────────────────────────
void loop() {
  // Reconnect if the router dropped. Scanning continues either way.
  if (netReady && WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi: link lost — reconnecting");
    netReady = connectWiFi(10000);
  }

  sendFrameStart();

  // Scan all rows, timing the full pass.
  uint32_t t0 = millis();
  for (int row = 0; row < NUM_ROWS; row++) {
    readRow(row);
    sendRow(row);          // stream each row as soon as it is read
  }
  lastScanMs = millis() - t0;

  sendFrameEnd();

#if SERIAL_DEBUG
  printGrid();
#endif

  frameId++;
  delay(FRAME_DELAY);
}