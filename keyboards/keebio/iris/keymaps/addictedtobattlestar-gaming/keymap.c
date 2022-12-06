#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0

// prettier-ignore
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RGB_TOG,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_MINS, KC_6,    KC_LEFT, KC_UP,   KC_RGHT, KC_7,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_TAB,  KC_8,    KC_LEFT, KC_DOWN, KC_RGHT, KC_9,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_PLUS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MUTE,          KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT,KC_ENT),
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          KC_BSPC, KC_SPC,  KC_ENT,                     KC_SPC,  RESET,   KC_LALT
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )};

void encoder_update_user(uint8_t index, bool clockwise) {
    tap_code(clockwise ? KC_VOLU : KC_VOLD);
}
