/*
Copyright 2018 Mike Roberts

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    williamx98
#define PRODUCT         Sisyphus Keyboard
#define DESCRIPTION     Sisyphus Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* left columns are all onboard, right columns all on expander */
#define COL_EXPANDED { true, true, true, true, true, true, true, true, true, true, true, true, true, true, true}
#define MATRIX_COL_PINS { GPA3, GPA4, GPA5, GPA6, GPA7, GPA1, GPA2, GPB6, GPB7, GPB0, GPB1, GPB2, GPB3, GPB4, GPB5}
#define MATRIX_ROW_PINS { B7, B6, B5, D7, C6}

#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 1

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F1 }
#define ENCODER_RESOLUTION 2