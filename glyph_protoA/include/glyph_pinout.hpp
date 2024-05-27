#ifndef _GLYPH_PINOUT_HPP
#define _GLYPH_PINOUT_HPP

#include "core/pinout.hpp"

#define OLED_WIRE_INSTANCE Wire1
#define OLED_SDA 2
#define OLED_SCL 3

const Pinout pinout = {
    .joybus_data = 4,
    .nes_data = 4,
    .nes_clock = 5,
    .nes_latch = 6,
    .mux = -1,
    .nunchuk_detect = -1,
    .nunchuk_sda = -1,
    .nunchuk_scl = -1,
};

#endif