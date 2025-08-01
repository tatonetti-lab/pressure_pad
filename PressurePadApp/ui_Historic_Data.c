// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.3
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"

lv_obj_t *ui_Historic_Data = NULL;lv_obj_t *ui_HomeButton2 = NULL;lv_obj_t *ui_HOME2 = NULL;lv_obj_t *ui_Image3 = NULL;lv_obj_t *ui_UNDER_CONSTRUCTION = NULL;lv_obj_t *ui_Image4 = NULL;
// event funtions
void ui_event_HomeButton2( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_Home_Page, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_Home_Page_screen_init);
}
}

// build funtions

void ui_Historic_Data_screen_init(void)
{
ui_Historic_Data = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Historic_Data, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
ui_object_set_themeable_style_property(ui_Historic_Data, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BG_COLOR, _ui_theme_color_Background);
ui_object_set_themeable_style_property(ui_Historic_Data, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BG_OPA, _ui_theme_alpha_Background);
ui_object_set_themeable_style_property(ui_Historic_Data, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BORDER_COLOR, _ui_theme_color_Border);
ui_object_set_themeable_style_property(ui_Historic_Data, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BORDER_OPA, _ui_theme_alpha_Border);
lv_obj_set_style_border_width(ui_Historic_Data, 10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HomeButton2 = lv_btn_create(ui_Historic_Data);
lv_obj_set_width( ui_HomeButton2, 56);
lv_obj_set_height( ui_HomeButton2, 30);
lv_obj_set_x( ui_HomeButton2, -307 );
lv_obj_set_y( ui_HomeButton2, -206 );
lv_obj_set_align( ui_HomeButton2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_HomeButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_HomeButton2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
ui_object_set_themeable_style_property(ui_HomeButton2, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BG_COLOR, _ui_theme_color_Background);
ui_object_set_themeable_style_property(ui_HomeButton2, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BG_OPA, _ui_theme_alpha_Background);
ui_object_set_themeable_style_property(ui_HomeButton2, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BORDER_COLOR, _ui_theme_color_Border);
ui_object_set_themeable_style_property(ui_HomeButton2, LV_PART_MAIN| LV_STATE_DEFAULT, LV_STYLE_BORDER_OPA, _ui_theme_alpha_Border);
lv_obj_set_style_border_width(ui_HomeButton2, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_HomeButton2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_HomeButton2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_width(ui_HomeButton2, 25, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_spread(ui_HomeButton2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_x(ui_HomeButton2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_ofs_y(ui_HomeButton2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_HomeButton2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_HomeButton2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_HOME2 = lv_label_create(ui_HomeButton2);
lv_obj_set_width( ui_HOME2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_HOME2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_HOME2, LV_ALIGN_CENTER );
lv_label_set_text(ui_HOME2,"HOME");
lv_obj_set_style_text_font(ui_HOME2, &ui_font_Futura_Book, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image3 = lv_img_create(ui_Historic_Data);
lv_img_set_src(ui_Image3, &ui_img_historicdataiconsmall_png);
lv_obj_set_width( ui_Image3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image3, -365 );
lv_obj_set_y( ui_Image3, -205 );
lv_obj_set_align( ui_Image3, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image3, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_UNDER_CONSTRUCTION = lv_label_create(ui_Historic_Data);
lv_obj_set_width( ui_UNDER_CONSTRUCTION, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_UNDER_CONSTRUCTION, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_UNDER_CONSTRUCTION, LV_ALIGN_CENTER );
lv_label_set_text(ui_UNDER_CONSTRUCTION,"UNDER CONSTRUCTION");
lv_obj_set_style_text_font(ui_UNDER_CONSTRUCTION, &ui_font_Futura_Bold_56, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image4 = lv_img_create(ui_Historic_Data);
lv_img_set_src(ui_Image4, &ui_img_690597470);
lv_obj_set_width( ui_Image4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image4, -3 );
lv_obj_set_y( ui_Image4, 399 );
lv_obj_add_flag( ui_Image4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_HomeButton2, ui_event_HomeButton2, LV_EVENT_ALL, NULL);

}

void ui_Historic_Data_screen_destroy(void)
{
   if (ui_Historic_Data) lv_obj_del(ui_Historic_Data);

// NULL screen variables
ui_Historic_Data= NULL;
ui_HomeButton2= NULL;
ui_HOME2= NULL;
ui_Image3= NULL;
ui_UNDER_CONSTRUCTION= NULL;
ui_Image4= NULL;

}
