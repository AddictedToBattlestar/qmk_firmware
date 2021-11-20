#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUMPAD 1
#define _FUNCPAD 2
#define _ADJUST 3

#define A_RENAME LSFT(KC_F6)
#define A_EXTRACT LALT(LGUI(KC_M))
#define A_RUN LALT(LGUI(KC_R))

#define NUMPAD TT(_NUMPAD)
#define FUNCPAD MO(_FUNCPAD)
#define ADJUST MO(_ADJUST)

// prettier-ignore
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RGB_TOG,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,          KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          KC_LCTL, ADJUST,  LGUI_T(KC_BSPC),           KC_SPC,  NUMPAD,  KC_LALT
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_NUMPAD] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_N,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_PERC, KC_7,    KC_8,    KC_9,    KC_DLR,                             _______, _______, _______, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS,                             KC_LEFT, KC_UP,   KC_RGHT, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_PLUS, _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          KC_0,    KC_DOT,  KC_ENT,                    _______, NUMPAD,  FUNCPAD
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_FUNCPAD] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_F,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_PERC, KC_F7,   KC_F8,   KC_F9,   A_RENAME,                           _______, _______, _______, _______, _______, KC_F12,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_SLSH, KC_F4,   KC_F5,   KC_F6,   A_EXTRACT,                          KC_LEFT, KC_UP,   KC_RGHT, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_ASTR, KC_F1,   KC_F2,   KC_F3,   A_RUN,   _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                   _______, _______, _______
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_ADJUST] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           RGB_M_X, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, RESET,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           RGB_M_B, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_LPRN, KC_RPRN,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           RGB_M_K, RGB_VAD, RGB_SAD, RGB_HUD, KC_UNDS, KC_MINS,                            KC_LEFT, KC_UP,   KC_RGHT, _______, KC_LCBR, KC_RCBR,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           RGB_M_P, RGB_VAI, RGB_SAI, RGB_HUI, KC_EQL,  KC_PLUS, _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC, KC_RBRC,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______,  _______,                   RESET,  _______, _______
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )};

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        default:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;
        case _NUMPAD:
        case _FUNCPAD:
            tap_code(clockwise ? KC_PGUP : KC_PGDN);
            break;
        case _ADJUST:
            tap_code(clockwise ? KC_BRMU : KC_BRMD);
            break;
    }
}
