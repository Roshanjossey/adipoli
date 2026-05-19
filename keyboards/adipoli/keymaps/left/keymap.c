// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───────┬───────────┐
     * │ Q │ W │ E │ R │ T │ Esc   │ Backspace │
     * ├───┼───┼───┼───┼───┼───────┼───────────┤
     * │ A │ S │ D │ F │ G │ Enter │ ←         │
     * ├───┼───┼───┼───┼───┼───────┼───────────┤
     * │ Z │ X │ C │ V │ B │ Space │ →         │
     * └───┴───┴───┴───┴───┴───────┴───────────┘
     * ┌───┬───┬───┬───┬───┬───────┬───────────┐
     * │ 1 │ 2 │ 3 │ 4 │ 5 │ Esc   │ Backspace │
     * ├───┼───┼───┼───┼───┼───────┼───────────┤
     * │ Ä │ Ü │ Ö │ F │ € │ Enter │ ←         │
     * ├───┼───┼───┼───┼───┼───────┼───────────┤
     * │ Z │ X │ C │ V │ B │ Space │ →         │
     * └───┴───┴───┴───┴───┴───────┴───────────┘
     * ┌────┬────┬────┬────┬────┬───────┬───────────┐
     * │ F1 │ F2 │ F3 │ F4 │ F5 │ Esc   │ Backspace │
     * ├────┼────┼────┼────┼────┼───────┼───────────┤
     * │ A  │  S │ D  │ F  │ G  │ Enter │ ←         │
     * ├────┼────┼────┼────┼────┼───────┼───────────┤
     * │ Z  │ X  │ C  │ V  │ B  │ Space │ →         │
     * └────┴────┴────┴────┴────┴───────┴───────────┘
     */
    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,  KC_BSPC,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_RIGHT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  TO(1)
    ),
    [1] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,  KC_BSPC,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_RIGHT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  TO(2)
    ),
    [2] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_ESC,  KC_BSPC,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  QK_BOOTLOADER,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  TO(0)
    )
};
