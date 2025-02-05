/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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
#define PRODUCT_ID   0x3435
#define DEVICE_VER   0x0001
#define MANUFACTURER tshort

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

/* Use I2C or Serial, not both */
#define USE_SERIAL
//#define USE_I2C

/* Select hand configuration */
//#define MASTER_LEFT
// #define EE_HANDS
#define MASTER_RIGHT

// wiring of each half
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1 }
// MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }

#define DIODE_DIRECTION COL2ROW
#define SPLIT_USB_DETECT

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN D3
#define RGBLED_NUM 12

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3
