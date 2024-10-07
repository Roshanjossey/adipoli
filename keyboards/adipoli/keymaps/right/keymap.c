// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───────┬───────┬───┬───┬───┬───┬───┐
     * │ ↑     │ Tab   │ Y │ U │ I │ O │ P │
     * ├───────┼───────┼───┼───┼───┼───┼───┤
     * │ ↓     │ Shift │ H │ J │ K │ L │ ; │
     * ├───────┼───────┼───┼───┼───┼───┼───┤
     * │ Super │ Ctrl  │ N │ M │ , │ . │ / │
     * └───────┴───────┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        KC_UP,   KC_TAB,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        QK_BOOTLOADER, KC_LSFT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_LGUI, KC_LCTL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
    )
};
