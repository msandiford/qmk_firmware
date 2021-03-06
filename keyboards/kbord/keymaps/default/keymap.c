/* Copyright 2020 Martin Sandiford

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
#include QMK_KEYBOARD_H

#include <print.h>

#include "rgblight.h"
#include "oled/oled_driver.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_kbord( /* Base */
        KC_1, KC_2, KC_3,
        KC_4, KC_5, KC_6,
        KC_7, KC_8, KC_9,
        KC_A, KC_B, KC_C,
        KC_D, KC_E, KC_F,
        RGB_TOG, RGB_MOD
    )
};

void keyboard_pre_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;

    // Enable gate for RGB LED control
    palSetPadMode(GPIOA, 10, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOA, 10);
}

void keyboard_post_init_user(void) {
//    chThdSleepMilliseconds(5000);
//    print("keyboard_post_init_user\n");
//    uprintf("STM32_SYSCLK = %u\n", STM32_SYSCLK);
//    uprintf("STM32_HCLK = %u\n", STM32_HCLK);
//    uprintf("STM32_PCLK = %u\n", STM32_PCLK);
//    oled_init(OLED_ROTATION_0);
    rgblight_set();
}
