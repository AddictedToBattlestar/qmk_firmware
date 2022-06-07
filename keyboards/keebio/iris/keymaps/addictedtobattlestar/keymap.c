#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define A_RENAME LSFT(KC_F6)
#define A_EXTRACT LALT(LGUI(KC_M))
#define A_RUN LALT(LGUI(KC_R))

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

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
                                          KC_LCTL, LOWER, LGUI_T(KC_BSPC),              KC_SPC,  RAISE,   KC_LALT
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_RAISE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, _______,                            KC_LEFT, KC_UP,   KC_RGHT, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______, _______,          A_RENAME, _______, KC_DOWN, _______, _______, _______, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, ADJUST, _______,                   A_EXTRACT, _______, A_RUN
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_LOWER] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, _______,                            KC_LEFT, KC_UP,   KC_RGHT, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______, _______,          _______, _______, KC_DOWN, _______, _______, _______, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______,  _______,                   _______, ADJUST, _______
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_ADJUST] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, RESET,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, RESET,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, RGB_VAD, RGB_SAD, RGB_HUD, KC_MINS, RGB_RMOD,                           KC_LEFT, KC_UP,   KC_RGHT, _______, _______, RGB_M_X,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, RGB_VAI, RGB_SAI, RGB_HUI, KC_PLUS, RGB_MOD, _______,          KC_MPLY, _______, KC_DOWN, _______, RGB_M_B, RGB_M_K, RGB_M_P,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, _______,                   KC_MPRV, _______, KC_MNXT
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        default:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;
        case _LOWER:
            tap_code(clockwise ? KC_PGUP : KC_PGDN);
            break;
        case _RAISE:
            tap_code(clockwise ? KC_BRMU : KC_BRMD);
            break;
    }
}
