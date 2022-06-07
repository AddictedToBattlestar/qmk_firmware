/*
Copyright 2016 Google Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include QMK_KEYBOARD_H
#include "debug.h"
#include "mousekey.h"
#include "timer.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0     // Default Mac OSX layer
#define SYMB 1     // Symb layer
#define PC 2       // PC media layer

#define A_RENAME LSFT(KC_F6)
#define A_EXTRACT LALT(LGUI(KC_M))
#define A_RUN LALT(LGUI(KC_R))
#define TAB_L LGUI(LALT(KC_LEFT))
#define TAB_R LGUI(LALT(KC_RGHT))

enum
{
  KF_VERSION,

  // Diagonal mouse movement
  A_MUL,
  A_MUR,
  A_MDL,
  A_MDR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Basic layer (OSX)
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |   @   |   $  |   $  |   %  |  _   |           |   +  |   ^  |   &  |   *  |   (  |   )  |        |
 * |  Esc   |   1  |   2   |   3  |   4  |   5  |  -   |           |   =  |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+-------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |      |       |      |      |      |      |           |      |      |      |      |      |      |   |    |
 * |   `    |   Q  |   W   |   E  |   R  |   T  |  {   |           |   }  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+-------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | Tab    |   A  |   S   |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '"   |
 * |--------+------+-------+------+------+------|  (   |           |   )  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X   |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+-------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui | Alt  | Ctrl  |  PC  | SYMB |                                       | Run  | re-  | Ex   | Prev | Next |
 *   |      |      |       |      |      |                                       |      | name | tract| tab  | Tab  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Rght |       | Home | End  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  Up  |       | PgUp |        |      |
 *                                 | Bksp | Tab  |------|       |------| Enter  |Space |
 *                                 |      |      | Down |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [BASE] = LAYOUT_ergodox( // layer 0 : default
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,
        KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LPRN,
        KC_LGUI, KC_LALT, KC_LCTRL, TO(PC), TO(SYMB),
        KC_LEFT, KC_RGHT,
        KC_UP,
        KC_BSPC, KC_TAB, KC_DOWN,
        // right hand
        KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELT,
        KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_RPRN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        A_RUN, A_RENAME, A_EXTRACT, TAB_L, TAB_R,
        KC_HOME, KC_END,
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPC),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Run  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   -  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   +  |   *    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |  PC  | BASE |                                       |      |   0  |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Mute |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Play/ |Stop  |VolUp |       |      |Prev  |Next  |
 *                                 |Pause |      |------|       |------|      |      |
 *                                 |      |      |VolDn |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,TO(PC),TO(BASE),
        KC_NO, KC_MUTE,
        KC_VOLU,
        KC_MPLY, KC_MSTP, KC_VOLD,
       // right hand
       A_RUN,   KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_TRNS, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_MINS, KC_BSLS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_PLUS, KC_ASTR,
                         KC_TRNS,KC_0,    KC_DOT,  KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_MPRV, KC_MNXT
),
    /* Keymap 2: PC layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |   @   |   $  |   $  |   %  |  _   |           |   +  |   ^  |   &  |   *  |   (  |   )  |        |
 * |  Esc   |   1  |   2   |   3  |   4  |   5  |  -   |           |   =  |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+-------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |      |       |      |      |      |      |           |      |      |      |      |      |      |   |    |
 * |   `    |   Q  |   W   |   E  |   R  |   T  |  {   |           |   }  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+-------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
 * | Tab    |   A  |   S   |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '"   |
 * |--------+------+-------+------+------+------|  (   |           |   )  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X   |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+-------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Alt  | LGui  |  PC  | SYMB |                                       | Run  | re-  | Ex   | Prev | Next |
 *   |      |      |       |      |      |                                       |      | name | tract| tab  | Tab  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Rght |       | Home | End  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  Up  |       | PgUp |        |      |
 *                                 | Bksp | Tab  |------|       |------| Enter  |Space |
 *                                 |      |      | Down |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [PC] = LAYOUT_ergodox( // layer 0 : default
        // left hand
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,
        KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LPRN,
        KC_LCTRL, KC_LALT, KC_LGUI, TO(BASE), TO(SYMB),
        KC_LEFT, KC_RGHT,
        KC_UP,
        KC_BSPC, KC_TAB, KC_DOWN,
        // right hand
        KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELT,
        KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_RPRN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        A_RUN, A_RENAME, A_EXTRACT, TAB_L, TAB_R,
        KC_HOME, KC_END,
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPC),
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id)
  {
  case KF_VERSION:
    if (record->event.pressed)
    {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
  /* Mouse movement */
  case A_MUL:
    if (record->event.pressed)
    {
      mousekey_on(KC_MS_UP);
      mousekey_on(KC_MS_LEFT);
    }
    else
    {
      mousekey_off(KC_MS_UP);
      mousekey_off(KC_MS_LEFT);
    }
    mousekey_send();
    break;

  case A_MUR:
    if (record->event.pressed)
    {
      mousekey_on(KC_MS_UP);
      mousekey_on(KC_MS_RIGHT);
    }
    else
    {
      mousekey_off(KC_MS_UP);
      mousekey_off(KC_MS_RIGHT);
    }
    mousekey_send();
    break;

  case A_MDL:
    if (record->event.pressed)
    {
      mousekey_on(KC_MS_DOWN);
      mousekey_on(KC_MS_LEFT);
    }
    else
    {
      mousekey_off(KC_MS_DOWN);
      mousekey_off(KC_MS_LEFT);
    }
    mousekey_send();
    break;

  case A_MDR:
    if (record->event.pressed)
    {
      mousekey_on(KC_MS_DOWN);
      mousekey_on(KC_MS_RIGHT);
    }
    else
    {
      mousekey_off(KC_MS_DOWN);
      mousekey_off(KC_MS_RIGHT);
    }
    mousekey_send();
    break;
  }
  return MACRO_NONE;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer)
  {
  case PC:
    ergodox_right_led_1_on();
    break;
  case SYMB:
    ergodox_right_led_2_on();
    break;
  // case ???:
  //     ergodox_right_led_1_on();
  //     ergodox_right_led_2_on();
  //     break;
  default:
    // none
    break;
  }
}
