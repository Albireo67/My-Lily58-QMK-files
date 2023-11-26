/*
This is the c configuration file for the keymap

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

/* Select hand configuration */

//#define MASTER_LEFT
#define MASTER_RIGHT
//#define EE_HANDS

//N-Key Rollover may be turned on here
#define FORCE_NKRO

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

// Maximum of 8(!) layers available
#define LAYER_STATE_8BIT

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 5
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_INTERVAL 200
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 70

#define OLED_BRIGHTNESS 150 // Values 0 - 255
#define OLED_TIMEOUT 120000  // Helps reduce OLED Burn-in. Time in ms.
#define OLED_SCROLL_TIMEOUT 60000 // Helps reduce OLED Burn-in. Set to 0 to disable.
//#define OLED_FONT_H "keyboards/lily58/keymaps/Albireo67/my_glcdfont.c"


// My Lily58 Classic do not have any RGB LEDs, so don´t need this section
/*
#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
// Underglow
#undef RGBLED_NUM
#define RGBLED_NUM 14    // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
*/
