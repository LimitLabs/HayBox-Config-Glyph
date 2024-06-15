#ifndef _NEOPIXEL_DEFINITIONS_HPP
#define _NEOPIXEL_DEFINITIONS_HPP

#include <config.pb.h>

#define LED_PIN 7
#define LED_COUNT 72

// clang-format off
const Button pixel_to_button_mappings[LED_COUNT] = {
    BTN_MB1, BTN_MB1,
    BTN_LF4, BTN_LF4,
    BTN_LF3, BTN_LF3,
    BTN_LF5, BTN_LF5,
    BTN_LF2, BTN_LF2,
    BTN_LF1, BTN_LF1,
    BTN_LF8, BTN_LF8,
    BTN_LF7, BTN_LF7,
    BTN_LF6, BTN_LF6,
    BTN_RF13, BTN_RF13,
    BTN_RF14, BTN_RF14,
    BTN_RF15, BTN_RF15,
    BTN_RF5, BTN_RF5,
    BTN_RF6, BTN_RF6,
    BTN_RF7, BTN_RF7,
    BTN_RF8, BTN_RF8,
    BTN_RF4, BTN_RF4,
    BTN_RF3, BTN_RF3,
    BTN_RF2, BTN_RF2,
    BTN_RF1, BTN_RF1,
    BTN_RF12, BTN_RF12,
    BTN_RF11, BTN_RF11,
    BTN_RF10, BTN_RF10,
    BTN_RT3, BTN_RT3,
    BTN_RT4, BTN_RT4,
    BTN_RT5, BTN_RT5,
    BTN_RT1, BTN_RT1,
    BTN_RT1, BTN_RT1,
    BTN_RT2, BTN_RT2,
    BTN_LT6, BTN_LT6,
    BTN_LT3, BTN_LT3,
    BTN_LT4, BTN_LT4,
    BTN_LT5, BTN_LT5,
    BTN_LT1, BTN_LT1,
    BTN_LT1, BTN_LT1,
    BTN_LT2, BTN_LT2,
};
// clang-format on

#endif