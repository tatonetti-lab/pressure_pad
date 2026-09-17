#include <Wire.h>
#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"
#include "lvgl.h"
#include "ui.h"

// --- LVGL Object References ---
extern lv_obj_t *ui_heatmap;
extern lv_obj_t *ui_Live_Data;
extern lv_obj_t *ui_Live_Data_Overview;

// --- Zone Buttons ---
extern lv_obj_t *ui_Z01;
extern lv_obj_t *ui_Z02;
extern lv_obj_t *ui_Z03;
extern lv_obj_t *ui_Z04;
extern lv_obj_t *ui_Z05;
extern lv_obj_t *ui_Z06;
extern lv_obj_t *ui_Z07;
extern lv_obj_t *ui_Z08;
extern lv_obj_t *ui_Z09;
extern lv_obj_t *ui_Z10;
extern lv_obj_t *ui_Z11;
extern lv_obj_t *ui_Z12;

// --- Hardware & Grid ---
Arduino_H7_Video Display(800, 480, GigaDisplayShield);
Arduino_GigaDisplayTouch Touch;

lv_obj_t *heatmap_cells[8][8];
int grid[24][32];  // Pressure values

lv_obj_t *zone_btn[12];
bool overview_initialized = false;
int current_zone = 0;

// --- Zone Struct ---
struct Zone {
  int startX;
  int startY;
  int width;
  int height;
};

Zone zones[12] = {
  { 24, 16, 8, 8 }, { 16, 16, 8, 8 }, { 8, 16, 8, 8 }, { 0, 16, 8, 8 },
  { 24, 8, 8, 8 },  { 16, 8, 8, 8 },  { 8, 8, 8, 8 },  { 0, 8, 8, 8 },
  { 24, 0, 8, 7 },  { 16, 0, 8, 7 },  { 8, 0, 8, 7 },  { 0, 0, 8, 7 }
};

// --- Pin Mapping ---
const int muxA0[] = { D51, D44, D39 };
const int muxA1[] = { D49, D42, D37 };
const int demuxA0[] = { D32, D27, D18, D15 };
const int demuxA1[] = { D30, D25, D17, D14 };

// --- Link Zone Buttons ---
void link_zone_buttons() {
  lv_obj_t *btns[] = {
    ui_Z01, ui_Z02, ui_Z03, ui_Z04, ui_Z05, ui_Z06,
    ui_Z07, ui_Z08, ui_Z09, ui_Z10, ui_Z11, ui_Z12
  };
  for (int i = 0; i < 12; i++) zone_btn[i] = btns[i];
}

// --- I2C Selection ---
void select_mux(int muxIndex, int channel) {
  digitalWrite(muxA0[muxIndex], channel & 0x01);
  digitalWrite(muxA1[muxIndex], (channel >> 1) & 0x01);
}

void select_demux(int demuxIndex, int channel) {
  digitalWrite(demuxA0[demuxIndex], channel & 0x01);
  digitalWrite(demuxA1[demuxIndex], (channel >> 1) & 0x01);
}

// --- Read All Grid Values ---
void update_sensor_grid() {
  // Zone definitions: {muxIndex, demuxIndex, analogPin}
  struct ZoneConfig {
    int muxIndex;
    int demuxIndex;
    int analogPin;
  };

  ZoneConfig zoneConfig[12] = {
    {0, 0, A2}, {0, 1, A2}, {0, 2, A2}, {0, 3, A2},
    {1, 0, A1}, {1, 1, A1}, {1, 2, A1}, {1, 3, A1},
    {2, 0, A0}, {2, 1, A0}, {2, 2, A0}, {2, 3, A0}
  };

  for (int zone = 0; zone < 12; zone++) {
    int muxChip = zoneConfig[zone].muxIndex;
    int demuxChip = zoneConfig[zone].demuxIndex;
    int analogPin = zoneConfig[zone].analogPin;

    for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
      select_demux(demuxChip, rowIndex);
      delayMicroseconds(50);

      for (int colIndex = 0; colIndex < 8; colIndex++) {
        select_mux(muxChip, colIndex);
        delayMicroseconds(50);

        int value = analogRead(analogPin);

        // Map column/row to full grid coordinates
        int gridX = 8 * (2 - muxChip) + colIndex;   // X: right to left
        int gridY = 8 * (3 - demuxChip) + rowIndex; // Y: bottom to top

        if (gridX >= 0 && gridX < 24 && gridY >= 0 && gridY < 32) {
          grid[gridX][gridY] = value;
        }
      }
    }
  }
}

// --- Heatmap Initialization ---
void init_heatmap() {
  if (!ui_heatmap) {
    Serial.println("ERROR: ui_heatmap is NULL");
    return;
  }

  lv_obj_clean(ui_heatmap);
  lv_obj_clear_flag(ui_heatmap, LV_OBJ_FLAG_SCROLLABLE);

  int containerW = lv_obj_get_width(ui_heatmap);
  int containerH = lv_obj_get_height(ui_heatmap);

  int cellW = (containerW + 7) / 8;
  int cellH = (containerH + 7) / 8;

  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      lv_obj_t *rect = lv_obj_create(ui_heatmap);
      lv_obj_set_size(rect, cellW, cellH);
      lv_obj_set_pos(rect, x * cellW, y * cellH);

      lv_obj_set_style_border_width(rect, 0, LV_PART_MAIN);
      lv_obj_set_style_radius(rect, 0, LV_PART_MAIN);
      lv_obj_set_style_bg_opa(rect, LV_OPA_COVER, LV_PART_MAIN);
      lv_obj_set_style_bg_color(rect, lv_color_make(0, 0, 255), LV_PART_MAIN);

      heatmap_cells[y][x] = rect;
    }
  }
  Serial.println("Heatmap initialized");
}

// --- Heatmap Cleanup ---
void cleanup_heatmap() {
  if (!ui_heatmap) return;
  lv_obj_clean(ui_heatmap);
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      heatmap_cells[y][x] = nullptr;
    }
  }
  Serial.println("Heatmap cleaned up");
}

// --- Heatmap Update ---
void update_heatmap() {
  Zone z = zones[current_zone];

  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      if (!heatmap_cells[y][x]) continue;

      int val = 0;
      if (y >= z.height) {
        val = 0;  // Black beyond defined height
      } else {
        int gy = z.startY + y;
        int gx = z.startX + x;
        if (gy >= 24 || gx >= 32) {
          val = 0;  // Clamp grid access
        } else {
          val = grid[gy][gx];
        }
      }

      int red = map(val, 0, 4095, 0, 255);
      int blue = 255 - red;

      lv_obj_set_style_bg_color(
        heatmap_cells[y][x],
        lv_color_make(red, 0, blue),
        LV_PART_MAIN);
    }
  }
}

// --- Calculate Average Zone Pressure ---
int calculate_zone_average(int zone_id) {
  int total = 0;
  int count = 0;
  Zone z = zones[zone_id];

  for (int y = 0; y < z.height; y++) {
    for (int x = 0; x < z.width; x++) {
      int gy = z.startY + y;
      int gx = z.startX + x;
      if (gy >= 24 || gx >= 32) continue;
      total += grid[gy][gx];
      count++;
    }
  }
  return (count > 0) ? total / count : 0;
}

// --- Update Zone Button Colors ---
void update_zone_colors() {
  if (!overview_initialized) return;

  for (int i = 0; i < 12; i++) {
    if (!zone_btn[i]) continue;

    int avg = calculate_zone_average(i);
    int red = map(avg, 0, 4095, 0, 255);
    int blue = 255 - red;

    lv_obj_set_style_bg_color(zone_btn[i],
                              lv_color_make(red, 0, blue),
                              LV_PART_MAIN);
  }
}

// --- Setup ---
void setup() {
  Serial.begin(115200);
  Wire.begin();
  Display.begin();
  Touch.begin();
  ui_init();

  // Set control pins as OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(muxA0[i], OUTPUT);
    pinMode(muxA1[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(demuxA0[i], OUTPUT);
    pinMode(demuxA1[i], OUTPUT);
  }

  // UI Event Handlers
  lv_obj_add_event_cb(ui_Live_Data_Overview, [](lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_SCREEN_LOADED) {
      link_zone_buttons();
      overview_initialized = true;
    } else if (lv_event_get_code(e) == LV_EVENT_SCREEN_UNLOADED) {
      overview_initialized = false;
    }
  }, LV_EVENT_ALL, NULL);

  lv_obj_add_event_cb(ui_Live_Data, [](lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_SCREEN_LOADED) {
      init_heatmap();
    } else if (lv_event_get_code(e) == LV_EVENT_SCREEN_UNLOADED) {
      cleanup_heatmap();
    }
  }, LV_EVENT_ALL, NULL);
}

// --- Main Loop ---
void loop() {
  lv_timer_handler();
  delay(5);

  static unsigned long lastUpdate = 0;
  static unsigned long lastZoneUpdate = 0;

  if (millis() - lastUpdate > 200) {
    update_sensor_grid();
    update_heatmap();
    lastUpdate = millis();
  }

  if (millis() - lastZoneUpdate > 1000) {
    update_zone_colors();
    lastZoneUpdate = millis();
  }
}