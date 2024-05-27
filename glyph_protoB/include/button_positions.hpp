#ifndef _BUTTON_POSITIONS_HPP
#define _BUTTON_POSITIONS_HPP

#define MENU_BUTTON_RADIUS 2
#define NORMAL_BUTTON_RADIUS 4
#define LARGE_BUTTON_RADIUS 5

#include "display/InputDisplay.hpp"

InputViewerButton full_layout_buttons[] = {
    {BTN_LF4,   6,   29, NORMAL_BUTTON_RADIUS},
    { BTN_LF3,  15,  23, NORMAL_BUTTON_RADIUS},
    { BTN_LF2,  25,  22, NORMAL_BUTTON_RADIUS},
    { BTN_LF1,  35,  27, NORMAL_BUTTON_RADIUS},
    { BTN_LF5,  24,  32, NORMAL_BUTTON_RADIUS},

    { BTN_RF1,  93,  27, NORMAL_BUTTON_RADIUS},
    { BTN_RF2,  102, 23, NORMAL_BUTTON_RADIUS},
    { BTN_RF3,  112, 24, NORMAL_BUTTON_RADIUS},
    { BTN_RF4,  122, 29, NORMAL_BUTTON_RADIUS},

    { BTN_RF5,  93,  17, NORMAL_BUTTON_RADIUS},
    { BTN_RF6,  102, 13, NORMAL_BUTTON_RADIUS},
    { BTN_RF7,  112, 14, NORMAL_BUTTON_RADIUS},
    { BTN_RF8,  122, 19, NORMAL_BUTTON_RADIUS},

    { BTN_LT1,  38,  52, NORMAL_BUTTON_RADIUS},
    { BTN_LT2,  46,  58, NORMAL_BUTTON_RADIUS},
    { BTN_LT3,  46,  46, NORMAL_BUTTON_RADIUS},
    { BTN_LT4,  38,  40, NORMAL_BUTTON_RADIUS},
    { BTN_LT5,  30,  46, NORMAL_BUTTON_RADIUS},
    { BTN_LT6,  59,  50, LARGE_BUTTON_RADIUS },

    { BTN_RT1,  90,  52, NORMAL_BUTTON_RADIUS},
    { BTN_RT2,  82,  58, NORMAL_BUTTON_RADIUS},
    { BTN_RT3,  82,  46, NORMAL_BUTTON_RADIUS},
    { BTN_RT4,  90,  40, NORMAL_BUTTON_RADIUS},
    { BTN_RT5,  98,  46, NORMAL_BUTTON_RADIUS},

    { BTN_LF6,  35,  17, NORMAL_BUTTON_RADIUS},
    { BTN_LF7,  46,  19, NORMAL_BUTTON_RADIUS},
    { BTN_LF8,  55,  25, NORMAL_BUTTON_RADIUS},

    { BTN_RF9,  64,  30, NORMAL_BUTTON_RADIUS},
    { BTN_RF10, 74,  25, NORMAL_BUTTON_RADIUS},
    { BTN_RF11, 84,  25, NORMAL_BUTTON_RADIUS},

    { BTN_RF12, 64,  20, NORMAL_BUTTON_RADIUS},
    { BTN_RF13, 74,  15, NORMAL_BUTTON_RADIUS},
    { BTN_RF14, 84,  15, NORMAL_BUTTON_RADIUS},
};
size_t full_layout_buttons_count = count_of(full_layout_buttons);

InputViewerButton platform_fighter_buttons[] = {
    {BTN_LF4,  6,   29, NORMAL_BUTTON_RADIUS},
    { BTN_LF3, 15,  23, NORMAL_BUTTON_RADIUS},
    { BTN_LF2, 25,  22, NORMAL_BUTTON_RADIUS},
    { BTN_LF1, 35,  27, NORMAL_BUTTON_RADIUS},
    { BTN_LF5, 24,  32, NORMAL_BUTTON_RADIUS},

    { BTN_RF1, 93,  27, NORMAL_BUTTON_RADIUS},
    { BTN_RF2, 102, 23, NORMAL_BUTTON_RADIUS},
    { BTN_RF3, 112, 24, NORMAL_BUTTON_RADIUS},
    { BTN_RF4, 122, 29, NORMAL_BUTTON_RADIUS},

    { BTN_RF5, 93,  17, NORMAL_BUTTON_RADIUS},
    { BTN_RF6, 102, 13, NORMAL_BUTTON_RADIUS},
    { BTN_RF7, 112, 14, NORMAL_BUTTON_RADIUS},
    { BTN_RF8, 122, 19, NORMAL_BUTTON_RADIUS},

    { BTN_LT1, 38,  52, NORMAL_BUTTON_RADIUS},
    { BTN_LT2, 46,  58, NORMAL_BUTTON_RADIUS},
    { BTN_LT3, 46,  46, NORMAL_BUTTON_RADIUS},
    { BTN_LT4, 38,  40, NORMAL_BUTTON_RADIUS},
    { BTN_LT5, 30,  46, NORMAL_BUTTON_RADIUS},

    { BTN_RT1, 90,  52, NORMAL_BUTTON_RADIUS},
    { BTN_RT2, 82,  58, NORMAL_BUTTON_RADIUS},
    { BTN_RT3, 82,  46, NORMAL_BUTTON_RADIUS},
    { BTN_RT4, 90,  40, NORMAL_BUTTON_RADIUS},
    { BTN_RT5, 98,  46, NORMAL_BUTTON_RADIUS},
};
size_t platform_fighter_buttons_count = count_of(platform_fighter_buttons);

InputViewerButton split_fgc_buttons[] = {
    {BTN_LF3,  15,  23, NORMAL_BUTTON_RADIUS},
    { BTN_LF2, 25,  22, NORMAL_BUTTON_RADIUS},
    { BTN_LF1, 35,  27, NORMAL_BUTTON_RADIUS},
    { BTN_LF5, 24,  32, NORMAL_BUTTON_RADIUS},

    { BTN_RF1, 93,  27, NORMAL_BUTTON_RADIUS},
    { BTN_RF2, 102, 23, NORMAL_BUTTON_RADIUS},
    { BTN_RF3, 112, 24, NORMAL_BUTTON_RADIUS},
    { BTN_RF4, 122, 29, NORMAL_BUTTON_RADIUS},

    { BTN_RF5, 93,  17, NORMAL_BUTTON_RADIUS},
    { BTN_RF6, 102, 13, NORMAL_BUTTON_RADIUS},
    { BTN_RF7, 112, 14, NORMAL_BUTTON_RADIUS},
    { BTN_RF8, 122, 19, NORMAL_BUTTON_RADIUS},

    { BTN_LT1, 38,  52, LARGE_BUTTON_RADIUS },
    { BTN_RT1, 90,  52, LARGE_BUTTON_RADIUS },
};
size_t split_fgc_buttons_count = count_of(split_fgc_buttons);

InputViewerButton fgc_buttons[] = {
    {BTN_LF6,   35, 17, NORMAL_BUTTON_RADIUS},
    { BTN_LF7,  46, 19, NORMAL_BUTTON_RADIUS},
    { BTN_LF8,  55, 25, NORMAL_BUTTON_RADIUS},

    { BTN_RF9,  64, 30, NORMAL_BUTTON_RADIUS},
    { BTN_RF10, 74, 25, NORMAL_BUTTON_RADIUS},
    { BTN_RF11, 84, 25, NORMAL_BUTTON_RADIUS},
    { BTN_RF1,  93, 27, NORMAL_BUTTON_RADIUS},

    { BTN_RF12, 64, 20, NORMAL_BUTTON_RADIUS},
    { BTN_RF13, 74, 15, NORMAL_BUTTON_RADIUS},
    { BTN_RF14, 84, 15, NORMAL_BUTTON_RADIUS},
    { BTN_RF5,  93, 17, NORMAL_BUTTON_RADIUS},

    { BTN_LT6,  59, 50, LARGE_BUTTON_RADIUS }
};
size_t fgc_buttons_count = count_of(fgc_buttons);

#endif