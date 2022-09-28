// Copyright 2022 syepm (@syepm)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS  12
#define MATRIX_COLS  6
#define MATRIX_ROW_PINS \
    { B5, B4, E6, D7, C6, D4 }

// wiring of each half
#define MATRIX_COL_PINS \
    { B3, B1, F7, F6, F5, F4 }

#define ENCODERS_PAD_A { D3, B2, B6 }
#define ENCODERS_PAD_B { B2, B6, D3 }

#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

#define DIODE_DIRECTION COL2ROW

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 100

#define OLED_FONT_H "keyboards/kk_key/glcdfont.c"

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define USE_SERIAL
