#ifndef _MATRIX_DEFINITION_HPP
#define _MATRIX_DEFINITION_HPP

#include "input/DebouncedSwitchMatrixInput.hpp"

#include <config.pb.h>

const size_t num_rows = 4;
const size_t num_cols = 11;
const uint row_pins[num_rows] = { 26, 25, 24, 23 };
const uint col_pins[num_cols] = { 15, 14, 13, 12, 16, 17, 21, 20, 19, 18, 22 };
// clang-format off
const Button matrix[num_rows][num_cols] = {
    {BTN_MB1,  BTN_MB2, BTN_MB3, BTN_MB4, BTN_MB5,  BTN_MB6,  BTN_MB7,  BTN_RF16, BTN_RF9, NA,      NA     },
    { BTN_LF3, BTN_LF2, BTN_LF8, BTN_LF7, BTN_RF13, BTN_RF14, BTN_RF15, BTN_RF5,  BTN_RF6, BTN_RF7, BTN_RF8},
    { BTN_LF4, BTN_LF5, BTN_LF1, BTN_LF6, BTN_RF10, BTN_RF11, BTN_RF12, BTN_RF1,  BTN_RF2, BTN_RF3, BTN_RF4},
    { BTN_LT5, BTN_LT4, BTN_LT1, BTN_LT3, BTN_LT2,  BTN_LT6,  BTN_RT2,  BTN_RT3,  BTN_RT1, BTN_RT4, BTN_RT5},
};
// clang-format on

DebouncedSwitchMatrixInput<num_rows, num_cols> matrix_input(
    row_pins,
    col_pins,
    matrix,
    DiodeDirection::COL2ROW
);

#endif