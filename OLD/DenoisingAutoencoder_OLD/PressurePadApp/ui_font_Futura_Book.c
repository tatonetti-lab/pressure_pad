/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font /Users/alexahitov/SquareLine/assets/FuturaCyrillicBold.ttf -o /Users/alexahitov/SquareLine/assets/ui_font_Futura_Book.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FUTURA_BOOK
#define UI_FONT_FUTURA_BOOK 1
#endif

#if UI_FONT_FUTURA_BOOK

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xdb, 0x6d, 0x87, 0xfc,

    /* U+0022 "\"" */
    0xfb, 0xbb,

    /* U+0023 "#" */
    0x36, 0x36, 0x7f, 0x7f, 0x36, 0xff, 0xff, 0x6c,
    0x6c, 0x6c,

    /* U+0024 "$" */
    0x18, 0x30, 0xf3, 0xe6, 0xe, 0x1f, 0x1f, 0xe,
    0x9f, 0xfb, 0xe1, 0x83, 0x0,

    /* U+0025 "%" */
    0x70, 0x8f, 0x90, 0xdb, 0xf, 0xa0, 0x74, 0x0,
    0x5e, 0xb, 0xf0, 0xb3, 0x13, 0x32, 0x1e,

    /* U+0026 "&" */
    0x3c, 0x1f, 0x86, 0x61, 0xd8, 0x3c, 0x1f, 0x4d,
    0xfb, 0x3c, 0xff, 0x1e, 0xe0,

    /* U+0027 "'" */
    0xea,

    /* U+0028 "(" */
    0x2d, 0xed, 0xb6, 0xdb, 0x36, 0x0,

    /* U+0029 ")" */
    0x9b, 0x36, 0xdb, 0x6f, 0xec, 0x0,

    /* U+002A "*" */
    0x27, 0x7e, 0xe5, 0x0,

    /* U+002B "+" */
    0x30, 0xcf, 0xff, 0x30, 0xc0,

    /* U+002C "," */
    0x66, 0x6c, 0xc0,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x3, 0x1, 0x81, 0x80, 0xc0, 0xc0, 0x60, 0x60,
    0x30, 0x30, 0x18, 0x18, 0xc, 0xc, 0x6, 0x0,

    /* U+0030 "0" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7,
    0x7e, 0x3c,

    /* U+0031 "1" */
    0xff, 0x33, 0x33, 0x33, 0x33,

    /* U+0032 "2" */
    0x38, 0xfb, 0x1e, 0x30, 0x61, 0x87, 0x1c, 0x7f,
    0xfc,

    /* U+0033 "3" */
    0x3c, 0x7e, 0x66, 0x6, 0xe, 0xf, 0x3, 0x63,
    0x7f, 0x3e,

    /* U+0034 "4" */
    0xe, 0x1e, 0x3e, 0x36, 0x66, 0x66, 0xff, 0xff,
    0x6, 0x6,

    /* U+0035 "5" */
    0x79, 0xe6, 0x3e, 0xfc, 0x30, 0xe3, 0xfb, 0xc0,

    /* U+0036 "6" */
    0x1c, 0x38, 0x30, 0x7e, 0xff, 0xe7, 0xc3, 0xe7,
    0x7e, 0x3c,

    /* U+0037 "7" */
    0xfe, 0xfe, 0xc, 0x1c, 0x18, 0x38, 0x70, 0x70,
    0xe0, 0xe0,

    /* U+0038 "8" */
    0x7d, 0xff, 0x1b, 0xf7, 0xd8, 0xf1, 0xe3, 0x7e,
    0xf8,

    /* U+0039 "9" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xe7, 0xff, 0x7e, 0xc,
    0x1c, 0x38,

    /* U+003A ":" */
    0xff, 0x8f, 0xf8,

    /* U+003B ";" */
    0x77, 0x70, 0x76, 0x6c, 0x80,

    /* U+003C "<" */
    0x4, 0x77, 0xb8, 0xe1, 0xe1, 0xc1,

    /* U+003D "=" */
    0xff, 0xff, 0xff,

    /* U+003E ">" */
    0x83, 0x87, 0x87, 0x1d, 0xee, 0x20,

    /* U+003F "?" */
    0x7d, 0xff, 0x98, 0x33, 0xc7, 0x0, 0x1c, 0x38,
    0x70,

    /* U+0040 "@" */
    0x1e, 0x30, 0x97, 0xb6, 0x5b, 0x2d, 0xb6, 0x7c,
    0x80, 0x60, 0x1f, 0x80,

    /* U+0041 "A" */
    0xe, 0x7, 0x81, 0xe0, 0xfc, 0x33, 0xc, 0xc7,
    0xf9, 0xfe, 0x61, 0xb8, 0x70,

    /* U+0042 "B" */
    0xf9, 0xfb, 0x36, 0x6f, 0xdf, 0xf1, 0xe3, 0xff,
    0xf8,

    /* U+0043 "C" */
    0x1e, 0xfd, 0x8e, 0xc, 0x18, 0x30, 0x31, 0x7e,
    0x3c,

    /* U+0044 "D" */
    0xfc, 0xfe, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc6,
    0xfe, 0xf8,

    /* U+0045 "E" */
    0xff, 0xfc, 0x30, 0xff, 0xfc, 0x30, 0xff, 0xf0,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xfb, 0xec, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x1f, 0x1f, 0xe6, 0x3b, 0x0, 0xc7, 0xf1, 0xfc,
    0x1d, 0x8e, 0x7f, 0x87, 0x80,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0049 "I" */
    0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0x18, 0xc6, 0x31, 0x8c, 0x6b, 0xfb, 0x80,

    /* U+004B "K" */
    0xc7, 0xce, 0xdc, 0xf8, 0xf0, 0xf8, 0xdc, 0xdc,
    0xce, 0xc7,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xff, 0xf0,

    /* U+004D "M" */
    0x71, 0xce, 0x39, 0xcf, 0x3d, 0xef, 0xbd, 0xff,
    0xf3, 0xbe, 0x73, 0xcc, 0x78, 0x8c,

    /* U+004E "N" */
    0xc1, 0xf0, 0xfc, 0x7f, 0x3d, 0xde, 0xef, 0x3f,
    0x8f, 0xc3, 0xe0, 0xc0,

    /* U+004F "O" */
    0x1e, 0x1f, 0xe6, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xd, 0x86, 0x7f, 0x87, 0x80,

    /* U+0050 "P" */
    0xfd, 0xff, 0x1e, 0x3c, 0x7f, 0xff, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x1e, 0x1f, 0xe6, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0x6d, 0x8e, 0x7f, 0x87, 0xf0,

    /* U+0052 "R" */
    0xfc, 0xfe, 0xc6, 0xc6, 0xfe, 0xfc, 0xfc, 0xdc,
    0xce, 0xc7,

    /* U+0053 "S" */
    0x7d, 0xfb, 0x87, 0xf, 0x8f, 0x83, 0x46, 0xfc,
    0xf0,

    /* U+0054 "T" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc0,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7,
    0x7e, 0x3c,

    /* U+0056 "V" */
    0xe1, 0xd8, 0x67, 0x39, 0xcc, 0x37, 0xf, 0xc1,
    0xe0, 0x78, 0x1c, 0x3, 0x0,

    /* U+0057 "W" */
    0xe3, 0xf, 0x8c, 0x76, 0x79, 0x99, 0xe6, 0x77,
    0xb8, 0xff, 0xe3, 0xcf, 0xf, 0x3c, 0x3c, 0xf0,
    0x61, 0x80,

    /* U+0058 "X" */
    0x73, 0x8c, 0xe3, 0xf0, 0x78, 0xe, 0x7, 0x83,
    0xf0, 0xfc, 0x73, 0xb8, 0x70,

    /* U+0059 "Y" */
    0xe7, 0x67, 0x7e, 0x3c, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0x7f, 0x7f, 0xe, 0xe, 0x1c, 0x1c, 0x38, 0x30,
    0x7f, 0x7f,

    /* U+005B "[" */
    0xff, 0x6d, 0xb6, 0xdb, 0x6d, 0xf8,

    /* U+005C "\\" */
    0xc0, 0x20, 0x18, 0x4, 0x3, 0x0, 0x80, 0x60,
    0x18, 0xc, 0x3, 0x1, 0x80, 0x60, 0x30, 0xc,

    /* U+005D "]" */
    0xfd, 0xb6, 0xdb, 0x6d, 0xb7, 0xf8,

    /* U+005E "^" */
    0x38, 0x51, 0xb3, 0x6c, 0x60,

    /* U+005F "_" */
    0xff, 0xfc,

    /* U+0060 "`" */
    0x46, 0x20,

    /* U+0061 "a" */
    0x7f, 0xff, 0x1e, 0x3c, 0x6f, 0xdf, 0x80,

    /* U+0062 "b" */
    0xc1, 0x83, 0x6, 0xf, 0xdf, 0xb1, 0xe3, 0xc7,
    0xfb, 0xe0,

    /* U+0063 "c" */
    0x3b, 0xf1, 0x8c, 0x3c, 0xe0,

    /* U+0064 "d" */
    0x6, 0xc, 0x18, 0x37, 0xef, 0xf1, 0xe3, 0xc6,
    0xfd, 0xf8,

    /* U+0065 "e" */
    0x38, 0xfb, 0xff, 0xfc, 0x6f, 0x8f, 0x0,

    /* U+0066 "f" */
    0x3b, 0xd8, 0xcf, 0xfd, 0x8c, 0x63, 0x18,

    /* U+0067 "g" */
    0x7e, 0xff, 0x1e, 0x3c, 0x7f, 0xdf, 0xe3, 0x7c,
    0x78,

    /* U+0068 "h" */
    0xc1, 0x83, 0x6, 0xd, 0xdf, 0xf1, 0xe3, 0xc7,
    0x8f, 0x18,

    /* U+0069 "i" */
    0xf0, 0xff, 0xfc,

    /* U+006A "j" */
    0xf0, 0xff, 0xff, 0xf0,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0xc, 0xfb, 0xbe, 0x78, 0xf9,
    0xbb, 0x38,

    /* U+006C "l" */
    0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0xfb, 0xbf, 0xfc, 0xcf, 0x33, 0xcc, 0xf3, 0x3c,
    0xcc,

    /* U+006E "n" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0x80,

    /* U+006F "o" */
    0x38, 0xfb, 0x1e, 0x3c, 0x6f, 0x8e, 0x0,

    /* U+0070 "p" */
    0xfd, 0xfb, 0x1e, 0x3c, 0x7f, 0xbe, 0x60, 0xc1,
    0x80,

    /* U+0071 "q" */
    0x7e, 0xff, 0x1e, 0x3c, 0x6f, 0xdf, 0x83, 0x6,
    0xc,

    /* U+0072 "r" */
    0xdf, 0xf1, 0x8c, 0x63, 0x0,

    /* U+0073 "s" */
    0x7f, 0xb0, 0xf1, 0xff, 0xc0,

    /* U+0074 "t" */
    0x66, 0xff, 0x66, 0x66, 0x60,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xdf, 0x0,

    /* U+0076 "v" */
    0xe7, 0x66, 0x7e, 0x3c, 0x3c, 0x18, 0x18,

    /* U+0077 "w" */
    0xe6, 0x33, 0x3b, 0x9f, 0xd8, 0x7e, 0xc3, 0xdc,
    0xc, 0xe0, 0x63, 0x0,

    /* U+0078 "x" */
    0x77, 0x1f, 0x7, 0x83, 0x83, 0xe3, 0xbb, 0x8e,

    /* U+0079 "y" */
    0xe3, 0x67, 0x76, 0x3e, 0x3c, 0x1c, 0x18, 0x38,
    0x30, 0x70,

    /* U+007A "z" */
    0xff, 0xe3, 0x8c, 0x73, 0xff, 0xc0,

    /* U+007B "{" */
    0x77, 0x66, 0x66, 0xee, 0x66, 0x66, 0x77,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xe7, 0x8c, 0x63, 0x18, 0xe7, 0x31, 0x8c, 0x6f,
    0x70,

    /* U+007E "~" */
    0x73, 0xfe, 0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 52, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 76, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 93, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 7, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 30, .adv_w = 200, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 169, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 50, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 59, .adv_w = 79, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 65, .adv_w = 79, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 71, .adv_w = 145, .box_w = 5, .box_h = 5, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 75, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 80, .adv_w = 93, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 83, .adv_w = 79, .box_w = 4, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 84, .adv_w = 68, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 102, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 134, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 68, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 88, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 201, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 207, .adv_w = 112, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 210, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 216, .adv_w = 123, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 164, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 159, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 132, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 156, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 110, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 286, .adv_w = 109, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 173, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 165, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 70, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 105, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 157, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 105, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 205, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 180, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 371, .adv_w = 183, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 183, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 140, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 106, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 162, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 157, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 227, .box_w = 14, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 159, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 143, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 141, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 75, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 513, .adv_w = 151, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 529, .adv_w = 75, .box_w = 3, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 535, .adv_w = 112, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 540, .adv_w = 112, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 542, .adv_w = 112, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 544, .adv_w = 138, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 566, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 127, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 77, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 137, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 599, .adv_w = 131, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 609, .adv_w = 60, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 60, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 616, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 60, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 629, .adv_w = 196, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 131, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 137, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 661, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 670, .adv_w = 92, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 99, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 73, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 685, .adv_w = 132, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 692, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 699, .adv_w = 201, .box_w = 13, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 711, .adv_w = 146, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 719, .adv_w = 135, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 729, .adv_w = 116, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 112, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 742, .adv_w = 112, .box_w = 2, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 746, .adv_w = 112, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 755, .adv_w = 112, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    8, 36,
    8, 40,
    8, 48,
    8, 50,
    8, 52,
    14, 34,
    14, 58,
    17, 18,
    17, 21,
    17, 24,
    18, 13,
    18, 15,
    18, 17,
    18, 18,
    18, 19,
    18, 20,
    18, 21,
    18, 22,
    18, 23,
    18, 24,
    18, 25,
    18, 26,
    19, 18,
    19, 24,
    20, 18,
    20, 24,
    21, 18,
    21, 21,
    21, 24,
    22, 18,
    22, 24,
    23, 18,
    23, 21,
    23, 24,
    24, 13,
    24, 15,
    24, 18,
    24, 19,
    24, 20,
    24, 21,
    24, 22,
    24, 23,
    24, 24,
    24, 25,
    24, 27,
    25, 18,
    25, 24,
    26, 17,
    26, 18,
    26, 24,
    34, 11,
    34, 14,
    34, 36,
    34, 40,
    34, 43,
    34, 48,
    34, 50,
    34, 52,
    34, 53,
    34, 55,
    34, 58,
    34, 87,
    34, 88,
    34, 90,
    35, 36,
    35, 53,
    35, 55,
    35, 57,
    35, 58,
    36, 40,
    36, 53,
    37, 34,
    37, 43,
    37, 46,
    37, 55,
    37, 57,
    37, 58,
    37, 59,
    37, 89,
    38, 53,
    39, 13,
    39, 14,
    39, 15,
    39, 34,
    39, 43,
    39, 52,
    39, 66,
    39, 68,
    39, 69,
    39, 70,
    39, 71,
    39, 74,
    39, 82,
    39, 84,
    39, 85,
    39, 89,
    39, 91,
    40, 34,
    40, 43,
    40, 55,
    40, 57,
    40, 58,
    40, 59,
    43, 34,
    43, 89,
    43, 91,
    44, 36,
    44, 40,
    44, 43,
    44, 48,
    44, 50,
    44, 52,
    44, 53,
    44, 54,
    44, 55,
    44, 66,
    44, 68,
    44, 69,
    44, 70,
    44, 72,
    44, 80,
    44, 81,
    44, 82,
    44, 84,
    44, 85,
    44, 86,
    44, 87,
    44, 88,
    44, 90,
    45, 11,
    45, 14,
    45, 36,
    45, 40,
    45, 48,
    45, 50,
    45, 52,
    45, 53,
    45, 54,
    45, 55,
    45, 56,
    45, 58,
    45, 87,
    45, 88,
    45, 90,
    46, 58,
    46, 88,
    46, 90,
    48, 34,
    48, 43,
    48, 46,
    48, 55,
    48, 57,
    48, 58,
    48, 59,
    48, 89,
    49, 13,
    49, 15,
    49, 34,
    49, 43,
    49, 46,
    49, 53,
    49, 57,
    49, 58,
    49, 59,
    49, 66,
    49, 68,
    49, 69,
    49, 70,
    49, 72,
    49, 80,
    49, 82,
    49, 84,
    49, 85,
    49, 87,
    49, 88,
    49, 89,
    49, 90,
    50, 58,
    51, 43,
    51, 53,
    51, 55,
    51, 58,
    51, 89,
    52, 43,
    52, 52,
    52, 56,
    52, 57,
    52, 58,
    53, 13,
    53, 15,
    53, 34,
    53, 43,
    53, 53,
    53, 58,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 72,
    53, 73,
    53, 75,
    53, 76,
    53, 77,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 84,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    55, 13,
    55, 15,
    55, 34,
    55, 43,
    55, 46,
    55, 48,
    55, 66,
    55, 67,
    55, 68,
    55, 69,
    55, 70,
    55, 71,
    55, 72,
    55, 73,
    55, 76,
    55, 78,
    55, 79,
    55, 80,
    55, 81,
    55, 82,
    55, 83,
    55, 84,
    55, 85,
    55, 86,
    55, 87,
    55, 88,
    55, 89,
    55, 90,
    55, 91,
    56, 34,
    56, 43,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 72,
    56, 73,
    56, 78,
    56, 79,
    56, 80,
    56, 81,
    56, 83,
    56, 84,
    56, 86,
    56, 87,
    56, 88,
    56, 89,
    56, 90,
    56, 91,
    57, 36,
    57, 40,
    57, 48,
    57, 50,
    57, 52,
    57, 66,
    57, 68,
    57, 69,
    57, 70,
    57, 72,
    57, 80,
    57, 81,
    57, 82,
    57, 86,
    57, 87,
    57, 88,
    57, 89,
    57, 90,
    58, 13,
    58, 14,
    58, 15,
    58, 27,
    58, 28,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 46,
    58, 48,
    58, 50,
    58, 52,
    58, 53,
    58, 55,
    58, 56,
    58, 66,
    58, 67,
    58, 68,
    58, 69,
    58, 70,
    58, 71,
    58, 72,
    58, 73,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 85,
    58, 86,
    58, 87,
    58, 88,
    58, 89,
    58, 90,
    58, 91,
    59, 36,
    59, 40,
    59, 46,
    59, 48,
    59, 50,
    59, 52,
    59, 66,
    59, 68,
    59, 69,
    59, 70,
    59, 80,
    59, 82,
    59, 84,
    59, 85,
    59, 86,
    59, 87,
    59, 88,
    59, 90,
    66, 53,
    66, 58,
    67, 34,
    67, 43,
    67, 53,
    67, 55,
    67, 56,
    67, 58,
    67, 84,
    67, 87,
    67, 88,
    67, 89,
    67, 90,
    68, 55,
    68, 58,
    68, 71,
    68, 85,
    70, 14,
    70, 53,
    70, 55,
    70, 58,
    70, 89,
    71, 34,
    71, 36,
    71, 40,
    71, 43,
    71, 48,
    71, 50,
    71, 67,
    71, 71,
    71, 73,
    71, 74,
    71, 77,
    71, 85,
    71, 87,
    71, 88,
    71, 90,
    72, 55,
    72, 58,
    73, 36,
    73, 40,
    73, 48,
    73, 50,
    73, 53,
    73, 54,
    73, 55,
    73, 56,
    73, 58,
    73, 66,
    73, 68,
    73, 69,
    73, 70,
    73, 72,
    73, 74,
    73, 80,
    73, 82,
    73, 83,
    73, 84,
    73, 86,
    76, 36,
    76, 40,
    76, 48,
    76, 50,
    76, 53,
    76, 54,
    76, 55,
    76, 56,
    76, 58,
    76, 66,
    76, 68,
    76, 69,
    76, 70,
    76, 72,
    76, 74,
    76, 80,
    76, 82,
    76, 83,
    76, 84,
    76, 86,
    78, 53,
    78, 55,
    78, 58,
    79, 53,
    79, 55,
    79, 58,
    80, 53,
    80, 55,
    80, 58,
    80, 87,
    80, 89,
    81, 34,
    81, 53,
    81, 55,
    81, 57,
    81, 58,
    81, 88,
    82, 55,
    82, 58,
    83, 13,
    83, 14,
    83, 15,
    83, 34,
    83, 43,
    83, 53,
    83, 55,
    83, 58,
    83, 68,
    83, 71,
    83, 72,
    83, 80,
    83, 82,
    83, 85,
    83, 90,
    84, 34,
    84, 53,
    84, 55,
    84, 58,
    85, 34,
    85, 40,
    85, 43,
    85, 48,
    85, 50,
    85, 55,
    85, 57,
    85, 58,
    85, 71,
    85, 85,
    85, 87,
    85, 88,
    85, 90,
    86, 34,
    86, 43,
    86, 55,
    86, 57,
    86, 58,
    87, 13,
    87, 15,
    87, 34,
    87, 43,
    87, 55,
    87, 57,
    87, 58,
    87, 69,
    87, 70,
    87, 72,
    87, 82,
    87, 89,
    88, 13,
    88, 15,
    88, 34,
    88, 43,
    88, 48,
    88, 53,
    88, 55,
    88, 57,
    88, 58,
    88, 66,
    88, 68,
    88, 69,
    88, 72,
    88, 80,
    88, 82,
    89, 36,
    89, 40,
    89, 48,
    89, 50,
    89, 53,
    89, 55,
    89, 58,
    89, 66,
    89, 68,
    89, 69,
    89, 70,
    89, 80,
    89, 82,
    90, 13,
    90, 15,
    90, 34,
    90, 36,
    90, 43,
    90, 53,
    90, 55,
    90, 57,
    90, 58,
    90, 66,
    90, 68,
    90, 69,
    90, 71,
    90, 82,
    90, 84,
    90, 85,
    91, 53,
    91, 55,
    91, 58
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    9, 9, 9, 11, 9, 6, -8, -17,
    6, -6, -28, -14, -19, -36, -28, -25,
    -25, -28, -19, -25, -19, -22, -19, -6,
    -22, -11, -17, 6, -11, -25, -11, -22,
    9, -11, -34, -28, -22, -8, -14, -14,
    -14, -17, -8, -14, -14, -19, -8, 6,
    -14, -8, -28, 6, -6, -4, 3, -4,
    -4, -6, -7, -11, -17, -6, -6, -6,
    -3, -9, -9, -11, -11, -6, 6, -8,
    -14, -3, -6, -8, -8, -8, -8, 6,
    -11, 11, -11, -9, -20, -6, -4, -4,
    -4, -4, 2, -2, -2, -9, 2, -11,
    -6, -9, -8, -6, -6, -8, -14, -6,
    -6, -6, -14, -14, -6, -8, -11, -11,
    -3, -8, -6, -11, -11, -8, -8, -6,
    -8, -3, -11, -6, -8, -8, -14, -14,
    -11, -17, 7, -8, -7, -8, -8, -6,
    -14, -8, -19, -11, -17, -11, -8, -11,
    -9, -6, -6, -4, -9, -3, -6, -11,
    -8, -6, -6, -13, -13, -17, -22, -8,
    3, -11, -6, -6, -3, -3, -6, -3,
    -6, -6, -6, -6, 3, 2, 3, -6,
    2, -3, -6, -6, -8, -11, 6, -6,
    -6, -8, -6, -6, -2, -2, -7, -11,
    10, 6, -8, -6, -11, -11, -8, -4,
    2, 2, 2, -4, -4, -8, -4, -8,
    -13, -9, -11, -11, -16, -11, -11, -11,
    -11, -11, -17, -8, -6, -13, -2, -13,
    -13, -11, -4, -11, -7, -2, -8, -7,
    -15, -9, -16, -8, -19, -6, -13, -8,
    -11, -16, -8, -16, -9, -14, -9, -9,
    -9, -9, -6, -8, -8, -8, -6, -8,
    -8, -12, -7, -4, -2, -11, -7, -9,
    -11, -6, -9, -9, -9, -9, -6, -9,
    -6, -3, -6, -6, -6, -3, -11, -11,
    6, -9, -19, -8, -20, -11, -11, -14,
    -11, -6, -25, -9, -9, -8, -11, 8,
    9, 8, -20, -2, -19, -25, -19, -11,
    -22, -4, -18, -16, -19, -16, -22, -20,
    -27, -12, -20, -16, -18, -25, -18, -21,
    -8, -6, -3, -6, -8, -6, -6, -8,
    -6, -6, -6, -6, -3, -8, -3, -11,
    -8, -8, -7, -11, -8, -6, -8, -14,
    -8, -22, -7, -6, -6, -6, -6, -9,
    -11, 4, 2, 14, -6, -8, -17, -2,
    -8, 3, 4, -8, 4, 6, 2, 7,
    2, 2, 2, 4, 4, 4, 4, -9,
    -17, -6, -6, -6, -6, -6, -3, -11,
    -6, -14, -8, -9, -6, -4, -6, -6,
    -4, -4, -6, -3, -6, -6, -6, -6,
    -6, -6, -3, -11, -6, -14, -8, -9,
    -6, -4, -6, -6, -4, -4, -6, -3,
    -6, -6, -11, -17, -9, -11, -20, -6,
    -14, -17, -2, -6, -6, -8, -8, -14,
    -14, -2, -11, -14, -7, 11, -7, -11,
    -14, -9, -11, -11, -4, 6, -2, -4,
    -2, 3, 6, -6, -8, -8, -17, -6,
    3, -8, 6, 3, -6, -6, -8, 9,
    6, 2, 2, 6, -6, -3, -6, -9,
    -11, -2, -2, -6, -14, -8, -11, -11,
    -2, -6, -2, -2, -6, -4, -4, -11,
    -11, 6, -9, -6, -11, -11, -8, -2,
    -2, -2, -2, -2, -6, -8, -8, -6,
    -11, -14, -17, -3, -4, -2, -9, -4,
    -2, -9, -7, -9, -6, -17, -9, -9,
    -11, -14, -8, -6, -2, 3, -2, -8,
    3, -11, -11, -17
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 532,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Futura_Book = {
#else
lv_font_t ui_font_Futura_Book = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FUTURA_BOOK*/

