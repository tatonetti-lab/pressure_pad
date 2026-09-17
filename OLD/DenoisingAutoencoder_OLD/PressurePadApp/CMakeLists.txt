SET(SOURCES ui_Home_Page.c
    ui_Live_Data.c
    ui_Historic_Data.c
    ui_Live_Data_Overview.c
    ui_theme_manager.c
    ui_themes.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_img_509871886.c
    ui_img_1742220310.c
    ui_img_690597470.c
    ui_img_livedataiconsmall_png.c
    ui_img_1401728645.c
    ui_img_1953993994.c
    ui_img_historicdataiconsmall_png.c
    ui_img_896003668.c
    ui_img_1485633761.c
    ui_img_1845464892.c
    ui_img_988524616.c
    ui_img_1671086701.c
    fonts/ui_font_Futura_Bold_56.c
    fonts/ui_font_Futura_Book.c
    fonts/ui_font_Futura_Book_26.c)

add_library(ui ${SOURCES})
