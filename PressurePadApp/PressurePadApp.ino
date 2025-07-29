#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"

#include "lvgl.h"
#include "ui.h"

// --- LVGL Object References ---
extern lv_obj_t *ui_heatmap;
extern lv_obj_t *ui_Live_Data;
extern lv_obj_t *ui_Live_Data_Overview;

// Zone buttons
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

// --- Hardware & Variables ---
Arduino_H7_Video Display(800, 480, GigaDisplayShield);
Arduino_GigaDisplayTouch Touch;

lv_obj_t *heatmap_cells[8][8];
int grid[24][32];  // Physical pad grid

lv_obj_t *zone_btn[12];
bool overview_initialized = false;
int current_zone = 0; // Active zone (0=Z01, 11=Z12)

// --- Zone Coordinates ---
struct Zone {
    int startX;
    int startY;
    int width;
    int height;
};

Zone zones[12] = {
    {24, 16, 8, 8},  // Z01
    {16, 16, 8, 8},  // Z02
    {8, 16, 8, 8},   // Z03
    {0, 16, 8, 8},   // Z04
    {24, 8, 8, 8},   // Z05
    {16, 8, 8, 8},   // Z06
    {8, 8, 8, 8},    // Z07
    {0, 8, 8, 8},    // Z08
    {24, 0, 8, 7},   // Z09
    {16, 0, 8, 7},   // Z10
    {8, 0, 8, 7},    // Z11
    {0, 0, 8, 7}     // Z12
};

// --- Link Zone Buttons ---
void link_zone_buttons() {
    zone_btn[0]  = ui_Z01;
    zone_btn[1]  = ui_Z02;
    zone_btn[2]  = ui_Z03;
    zone_btn[3]  = ui_Z04;
    zone_btn[4]  = ui_Z05;
    zone_btn[5]  = ui_Z06;
    zone_btn[6]  = ui_Z07;
    zone_btn[7]  = ui_Z08;
    zone_btn[8]  = ui_Z09;
    zone_btn[9]  = ui_Z10;
    zone_btn[10] = ui_Z11;
    zone_btn[11] = ui_Z12;
    Serial.println("Zone buttons linked");
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
                val = 0; // Black beyond defined height
            } else {
                int gy = z.startY + y;
                int gx = z.startX + x;
                if (gy >= 24 || gx >= 32) {
                    val = 0; // Clamp grid access
                } else {
                    val = grid[gy][gx];
                }
            }

            int red = map(val, 0, 4095, 0, 255);
            int blue = 255 - red;

            lv_obj_set_style_bg_color(
                heatmap_cells[y][x],
                lv_color_make(red, 0, blue),
                LV_PART_MAIN
            );
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

// --- Fake Sensor Data ---
void fake_sensor_update() {
    static int t = 0;
    t++;
    for (int y = 0; y < 24; y++) {
        for (int x = 0; x < 32; x++) {
            grid[y][x] = (sin((x + t) * 0.2) + cos((y + t) * 0.2)) * 2000 + 2000;
        }
    }
}

// --- Setup ---
void setup() {
    Serial.begin(115200);
    Display.begin();
    Touch.begin();
    ui_init();

    lv_obj_add_event_cb(ui_Live_Data_Overview, [](lv_event_t *e) {
        if (lv_event_get_code(e) == LV_EVENT_SCREEN_LOADED) {
            link_zone_buttons();
            overview_initialized = true;
        }
        else if (lv_event_get_code(e) == LV_EVENT_SCREEN_UNLOADED) {
            overview_initialized = false;
        }
    }, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_Live_Data, [](lv_event_t *e) {
        if (lv_event_get_code(e) == LV_EVENT_SCREEN_LOADED) {
            init_heatmap();
        }
        else if (lv_event_get_code(e) == LV_EVENT_SCREEN_UNLOADED) {
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
        fake_sensor_update();
        update_heatmap();
        lastUpdate = millis();
    }

    if (millis() - lastZoneUpdate > 1000) {
        update_zone_colors();
        lastZoneUpdate = millis();
    }
}