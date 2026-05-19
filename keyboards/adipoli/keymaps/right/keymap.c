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
     * ┌───────┬───────────┬───┬───┬───┬───┬───┐
     * │ Esc   │ Backspace │ 6 │ 7 │ 8 │ 9 │ 0 │
     * ├───────┼───────────┼───┼───┼───┼───┼───┤
     * │ Enter │ ←         │ ; │ ' │ ] │ \ │ G │
     * ├───────┼───────────┼───┼───┼───┼───┼───┤
     * │ Space │ →         │ Z │ X │ C │ V │ B │
     * └───────┴───────────┴───┴───┴───┴───┴───┘
     * ┌───────┬───────────┬────┬────┬────┬────┬────┐
     * │ Esc   │ Backspace │ F1 │ F2 │ F3 │ F4 │ F5 │
     * ├───────┼───────────┼────┼────┼────┼────┼────┤
     * │ Enter │ ←         │ A  │  S │ D  │ F  │ G  │
     * ├───────┼───────────┼────┼────┼────┼────┼────┤
     * │ Space │ →         │ Z  │ X  │ C  │ V  │ B  │
     * └───────┴───────────┴────┴────┴────┴────┴────┘
     */
    [0] = LAYOUT(
        KC_UP,   KC_TAB,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        QK_BOOTLOADER, KC_LSFT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        TO(1), KC_LCTL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
    ),
    [1] = LAYOUT(
        KC_1,    KC_2,    KC_6,    KC_7,    KC_8,    KC_9,  KC_0,
        KC_A,    KC_S,    KC_SEMICOLON,    KC_QUOTE,    KC_RIGHT_BRACKET,    KC_BACKSLASH,  QK_BOOTLOADER,
        TO(2),    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  MO(2)
    ),
    [2] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_ESC,  KC_BSPC,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  QK_BOOTLOADER,
        TO(0),    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  KC_RGHT
    )
};
