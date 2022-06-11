/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _NUMPAD 1
#define _FUNPAD 2
#define _SYMBOL 3
#define _ADJUST 4

#define NUMPAD TT(_NUMPAD)
#define SYMBOL MO(_SYMBOL)
#define FUNPAD MO(_FUNPAD)
#define ADJUST MO(_ADJUST)

#define A_RENAME LSFT(KC_F6)
#define A_EXTRACT LALT(LGUI(KC_M))
#define A_RUN LALT(LGUI(KC_R))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R, KC_MUTE,                      KC_MUTE,    KC_R,    KC_E,    KC_W,    KC_Q,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F, KC_VOLU,                      KC_VOLU,    KC_F,    KC_D,    KC_S,    KC_A,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V, KC_VOLD,                      KC_VOLD,    KC_V,    KC_C,    KC_X,    KC_Z, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LALT, KC_ENT,      KC_ENT, KC_LALT, KC_LCTL
                                      //`--------------------------'  `--------------------------'
  )
};
