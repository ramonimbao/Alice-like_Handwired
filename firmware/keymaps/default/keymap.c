/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

#include "quantum.h"

#undef ___
#define ___ KC_TRNS

#define _QWERTY 0
#define _COLEMAK 1
#define _RAISE 2
#define _LOWER 3
#define _ADJUST 4
#define _FN 5

enum custom_keycodes {
    KC_DESKTOP = SAFE_RANGE,
    KC_SNIP,
    KC_PROJECTOR,
    KC_QWERTY,
    KC_COLEMAK,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_DESKTOP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("d"));
            }
            break;
        case KC_SNIP:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("S"));
            }
            break;
        case KC_PROJECTOR:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("p"));
            }
            break;
        case KC_COLEMAK:
            if (record->event.pressed) {
                layer_move(_COLEMAK);
                layer_on(_ADJUST);
            }
            break;
        case KC_QWERTY:
            if (record->event.pressed) {
                layer_move(_QWERTY);
                layer_on(_ADJUST);
            }
    }
    return true;
}

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_RBRACKET, KC_BSLASH,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_GRAVE, KC_ENTER,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT, KC_RGUI,
        KC_LCTL, KC_LALT, MO(_LOWER), KC_SPACE, KC_BSPACE, MO(_RAISE), KC_RALT, KC_RCTL, MO(_FN)
    ),
    [_COLEMAK] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, KC_LBRACKET, KC_RBRACKET, KC_BSLASH,
        KC_CAPS, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOTE, KC_GRAVE, KC_ENTER,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT, KC_RGUI,
        KC_LCTL, KC_LALT, MO(_LOWER), KC_SPACE, KC_BSPACE, MO(_RAISE), KC_RALT, KC_RCTL, MO(_FN)
    ),
    [_RAISE] = LAYOUT(
        ___, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ___,
        ___, ___, KC_UP, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGUP, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, KC_HOME, ___, KC_END, KC_PGDN, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, ___, MO(_ADJUST), ___, ___, ___, ___, ___, ___
    ),
    [_LOWER] = LAYOUT(
        ___, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ___,
        ___, ___, ___, ___, ___, ___, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_KP_ASTERISK, ___, ___, ___,
        ___, ___, ___, ___, ___, ___, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_KP_SLASH, ___, ___, ___,
        ___, ___, ___, ___, ___, ___, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT, ___, ___, ___,
        ___, ___, ___, ___, KC_KP_0, MO(_ADJUST), ___, ___, ___
    ),
    [_ADJUST] = LAYOUT(
        KC_QWERTY, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, KC_COLEMAK,
        ___, ___, KC_PGUP, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, KC_HOME, KC_PGDN, KC_END, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, ___, ___, ___, ___, ___, ___
    ),
    [_FN] = LAYOUT(
        KC_DESKTOP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUMLOCK,
        ___, ___, KC_PGUP, KC_MY_COMPUTER, KC_CALC, KC_WWW_HOME, ___, ___, ___, KC_SNIP, KC_PROJECTOR, ___, ___, ___,
        ___, KC_HOME, KC_PGDN, KC_END, KC_BRID, KC_BRIU, ___, ___, ___, ___, ___, ___, ___, ___,
        ___, KC_VOLD, KC_MUTE, KC_VOLU, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, ___, ___, ___, ___, ___, ___, ___,
        ___, ___, ___, KC_MEDIA_PLAY_PAUSE, ___, ___, ___, ___, ___
    )
};
