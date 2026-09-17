# Pressure Sensor Pad for Real-Time Ulcer Detection
A smart pressure-sensing pad for early detection of pressure ulcers.

## Table of Contents
- [Project Overview](#project-overview)
  - [Motivation](#motivation)
  - [Clinical Grounding](#clinical-grounding)
- [Hardware](#hardware)
  - [Core Components](#core-components)
  - [Sensor Construction](#sensor-construction)
  - [Circuit Summary](#circuit-summary)
  - [Board Layout](#board-layout)
- [Software](#software)
  - [Arduino Firmware](#arduino-firmware)
  - [Wireless Streaming](#wireless-streaming)
- [Testing and Usage](#testing-and-usage)
  - [Power Supply](#power-supply)
  - [Firmware Upload](#firmware-upload)
  - [Hardware Guide](#hardware-guide)
  - [Incremental Build and Test](#incremental-build-and-test)
- [Current Results](#current-results)
- [Current Limitations](#current-limitations)
- [Critical Build Notes](#critical-build-notes)
- [Roadmap](#roadmap)
- [Troubleshooting Guide](#troubleshooting-guide)
- [File Structure](#file-structure)
- [Authors](#authors)

## Project Overview
This project is a custom-built pressure sensor pad designed to detect and monitor pressure distribution in surgical and ICU settings. The goal is to identify high-risk regions for pressure ulcers in real time, aiding in preventative care for hospitalized patients.

### Motivation
Pressure ulcers are a major complication for bedridden or post-surgical patients. This device aims to reduce incidence by:
- Continuously monitoring pressure points beneath a patient
- Alerting clinicians to prolonged or high-risk pressure areas
- Improving quality of care, particularly in oncology and ICU units

### Clinical Grounding
- Capillary closing pressures: arterial ~32 mmHg, venous 8 to 12 mmHg
- Interface pressure ranges vary by anatomical site and patient position
- Injury risk follows an inverse pressure/time relationship, so **pressure-time integration, not instantaneous pressure, is the clinically meaningful signal**
- NPUAP/EPUAP staging is the injury staging framework in use
- Braden Scale subscales are a potential source of metadata for alert weighting
- Deep Tissue Injury (DTI) is a distinct and particularly dangerous subcategory that surface sensors cannot directly detect

## Hardware

### Core Components
- **Microcontroller:** `Arduino GIGA R1 WiFi`
- **Sensor Matrix:** 34 column x 24 row grid (816 sensing cells) using `Velostat`, a piezoresistive plastic that changes resistance under pressure
- **Electrodes:** Conductive fabric strips (Amradield copper/nickel ripstop, under 0.03 ohm sheet resistance)
- **ADCs:** Eight `ADS1115` 16-bit I2C ADCs across two independent I2C buses
- **Boards:** Four `EPLZON` solderable protoboards, two ADS1115 chips per board
- **Connections:** 5mm sewable snaps and stainless conductive thread, 28AWG silicone wire
- **Networking:** Portable router on WPA2-Personal, UDP streaming to a host machine

> The previous design used `ADG728` analog switches on a custom `KiCad` PCB to scan one cell at a time. Both the multiplexers and the custom PCB have been removed from the design.

### Sensor Construction
The pad is a three-layer sandwich:

| Layer | Contents |
|---|---|
| Top cover | Row strips sewn onto a separate fabric cover |
| Center | Velostat sheet, mechanically fixed in place |
| Bottom cover | Column strips sewn onto a separate fabric cover |

Strip geometry:

| | Columns | Rows |
|---|---|---|
| Count | 34 | 24 |
| Strip width | 1.0 cm | 1.0 cm |
| Gap between strips | 1.5 cm | 1.5 cm |
| Pad dimension | ~86 cm | ~60 cm |

Strips are sewn onto the cover layers, never through the Velostat itself. See [Critical Build Notes](#critical-build-notes) for why.

### Circuit Summary
- One row at a time is driven HIGH directly from a GIGA digital pin
- All unselected rows are set to high-impedance (`INPUT`), not LOW
- Each column line forms a voltage divider with a 10 kohm pull-down to GND
- The ADS1115 chips read the column voltages, eight points at a time across the two buses
- Pressure lowers the Velostat resistance at the intersection, raising the column voltage

Typical response at a single cell:

| State | Voltage at column node |
|---|---|
| No pressure | ~0.3 to 0.5 V |
| Full pressure | ~3.2 V |

> Because rows are driven directly from GPIO, no multiplexers are required. The GIGA has 76 digital pins and the full design needs 24 for rows plus 4 for the two I2C buses.

### Board Layout
Each protoboard carries two ADS1115 chips, one on each I2C bus, sharing an address.

| Board | Bus / Address | Columns | ADDR pin wired to |
|---|---|---|---|
| Board 1 | Wire, 0x48 | 1 to 4 | GND |
| Board 1 | Wire2, 0x48 | 5 to 8 | GND |
| Board 2 | Wire, 0x49 | 9 to 12 | VDD |
| Board 2 | Wire2, 0x49 | 13 to 16 | VDD |
| Board 3 | Wire, 0x4A | 17 to 20 | SDA |
| Board 3 | Wire2, 0x4A | 21 to 24 | SDA |
| Board 4 | Wire, 0x4B | 25 to 28 | SCL |
| Board 4 | Wire2, 0x4B | 29 to 32 | SCL |

Chips on separate buses may share an I2C address without conflict.

**Arduino GIGA R1 WiFi I2C pin assignments:**

| Bus | SDA | SCL |
|---|---|---|
| `Wire` | pin 20 | pin 21 |
| `Wire2` | pin 9 | pin 8 |

> `Wire2` is not labelled as I2C on the GIGA silkscreen. Wiring it to pins 11/12 or 101/102 will fail to find the chip.

## Software

### Arduino Firmware
- Drives one row at a time from GIGA digital pins, holding all other rows high-impedance
- Reads all active column channels over both I2C buses
- Times each full scan and reports the measured duration
- Streams results over WiFi and prints to Serial as a fallback

The firmware uses preprocessor `#if` blocks keyed to `NUM_COLS`, incrementing by 4 per chip. Setting `NUM_COLS` and `NUM_ROWS` at the top of the sketch enables exactly the chips that are physically installed, so the system can be built and tested incrementally.

### Wireless Streaming
The pad joins a portable router running WPA2-Personal. Hospital networks typically use WPA2-Enterprise, which the GIGA does not support natively, so a dedicated router avoids the authentication problem entirely.

Data is sent as UDP packets, one packet per scanned row, which keeps every payload well under the MTU. A dropped packet costs one row rather than an entire frame.

```
FRAME,<frameId>,<rows>,<cols>,<scanTimeMs>
ROW,<frameId>,<rowIndex>,v0,v1,...,vN
END,<frameId>
```

A WiFi failure is non-fatal. The pad continues scanning and printing to Serial, and retries the connection in `loop()`.

## Testing and Usage

### Power Supply
- Arduino: USB-C or external 5V line
- Router: USB-C power bank

### Firmware Upload
1. Connect `Arduino GIGA R1 WiFi` via USB
2. Set `WIFI_SSID` and `WIFI_PASS` to the portable router credentials
3. Set `NUM_COLS` and `NUM_ROWS` to match the hardware currently installed
4. Upload the sketch using [**`Arduino IDE`**](https://www.arduino.cc/en/software/)

> Necessary libraries: `Adafruit_ADS1X15`, `Wire`, `WiFi`, `WiFiUdp`.

### Hardware Guide
1. Position the pad with the connection tabs accessible along the row and column edges
2. Connect each column strip to its assigned ADS1115 analog input through its snap and wire
3. Connect each column line to GND through a 10 kohm pull-down resistor
4. Connect each row strip to its assigned GIGA digital pin
5. Wire both I2C buses from the GIGA to all four protoboards in parallel, sharing 3.3V and GND
6. Confirm each board's ADDR pins are set per the [Board Layout](#board-layout) table
7. Power the board

### Incremental Build and Test
Build up the pad in groups of four columns. After wiring each new chip:

1. Set `NUM_COLS` to the new total and re-upload
2. Confirm the startup Serial output reports the new chip as found
3. Press each new cell individually and confirm only its column responds
4. Press two cells in the same column and confirm both register independently

Step 4 is the one that catches row isolation faults, which do not appear in single-point testing.

## Current Results
- Dual-bus parallel ADC architecture validated on the full pad
- 12 columns x 5 rows confirmed working with correct multi-point discrimination
- Clean pressure response and return to baseline across all tested cells
- No ghosting between rows or columns
- Wireless UDP streaming implemented
- Test deployment planned at a Cedars-Sinai surgical suite

## Current Limitations
- Only 12 columns x 5 rows are wired and validated so far; the remaining strips are cut and marked but not yet sewn
- Baseline resting voltage varies between strips, so per-cell calibration will be needed for cross-pad comparison
- Data is real-time only; historic pressure history is not yet stored
- Alert logic is not yet implemented
- The Arduino still requires a wired power source, so the system is not yet fully untethered
- Velostat must be handled carefully to avoid flex damage
- The conductive fabric contains nickel and should not contact patient skin directly; a non-conductive cover layer is required for clinical use

## Critical Build Notes
These are failure modes that cost significant debugging time. They are not obvious and are easy to reintroduce.

| Finding | Why it matters |
|---|---|
| The bare fabric face must contact the Velostat | Conductive tape adhesive insulates against Velostat even when the tape itself is conductive. Readings appear stable but do not respond to pressure. |
| Unselected rows must be `INPUT`, never `LOW` | Driving unselected rows LOW creates phantom current paths through pressed cells. Single-point readings look correct; multi-point readings are corrupted. |
| Velostat must be mechanically fixed | It shifts under load and can short the two fabric layers, collapsing resistance to zero. |
| Never sew strips through the Velostat along their length | The stitching compresses the material and corrupts the pressure signal. Sew strips onto cover layers instead. |

## Roadmap

| Milestone | Status |
|---|---|
| Initial prototype | Complete |
| Parallel ADC architecture | Complete |
| Conductive fabric sensor layer | Complete |
| Wireless data streaming | Complete |
| Full pad assembly (all rows and columns) | In progress |
| Battery power for full wireless operation | Planned |
| Real-time heatmap visualization | Planned |
| Historic data logging and alert logic | Planned |
| Clinical suite testing | Planned |

## Troubleshooting Guide

| Problem | Possible Cause | Solution |
|---|---|---|
| Nothing printed to Serial | Sketch halted in setup on a chip that was not found | Check the last Serial line before the halt to identify which chip failed |
| `ERROR: BoardN Wire2 chip not found` | SDA/SCL on the wrong pins | `Wire2` is SDA pin 9, SCL pin 8. It is not labelled on the silkscreen |
| Chip found but readings do not respond to pressure | Column wires on the wrong AIN channels | Verify the physical AIN channel matches the channel index in `readRow()` |
| Readings stable but unresponsive to pressure | Adhesive side of the electrode contacting the Velostat | Reorient so the bare fabric face is the contact surface |
| Resistance drops to 0 ohm under light pressure | Velostat shifting, allowing the fabric layers to touch | Fix the Velostat in place relative to the cover layers |
| Voltage drops when pressing multiple cells in one column | Unselected rows driven LOW instead of high-impedance | Set all unselected rows to `pinMode(pin, INPUT)` |
| One column always reads high or low | Missing or disconnected 10 kohm pull-down | Verify the pull-down connects the column line to GND |
| Two chips conflict on one bus | Duplicate I2C address | Check ADDR wiring against the Board Layout table |
| No UDP data received | Host and pad on different networks, or firewall blocking the port | Confirm both are on the portable router and that UDP 4210 is open on the host |
| Arduino not recognized in IDE | Wrong port or missing driver | Ensure correct port is selected and install the board package in Arduino IDE |
| Boot0 light flashing red after upload | Invalid code upload or memory overflow | Double-click the RST button on the Arduino and reupload |

## File Structure
<pre>
pressure_pad/
├── PressurePadApp/             # Arduino firmware
│   └── PressurePadApp.ino
├── Docs/                       # Slides, references, design notes
│   └── *.pdf
├── Assets/                     # Images for documentation
│   └── *.png
└── DenoisingAutoencoder_OLD/   # Legacy Python scripts and ML notebooks
    ├── no_touch_set/
    ├── 6x6/
    ├── *.ipynb
    └── pressure_pad_study.db
</pre>

## Authors

- [@AlexAhitov](https://github.com/AlexAhitov)

[**Back to the top**](#pressure-sensor-pad-for-real-time-ulcer-detection)
