#include QMK_KEYBOARD_H

// Layer shorthand
enum layer {
  _BASE,
  _LOWER
};

#define LOWER MO(1)

// Mac sleep
#define __SLEEP S(LCTL(KC_POWER))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_hhkb(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    LSFT(KC_F6), LALT(LGUI(KC_M)),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELT, \
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,     KC_EQL,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,     KC_RBRC,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RGB_TOG,     RGB_MOD,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
           KC_LGUI, KC_LALT, KC_LCTL, LOWER,       KC_BSPC,                  KC_SPC,              KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  ),

  [_LOWER] = LAYOUT_ortho_hhkb(
    RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     LALT(LGUI(KC_R)),    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  _______, _______, _______, _______, _______, _______, _______,     _______,             _______,   KC_UP, _______, _______, _______, KC_F12,  \
  KC_MPLY, _______, _______, _______, _______, _______, _______,     _______,             KC_LEFT, _______, KC_RGHT, _______, _______, _______, \
  KC_MUTE, _______, _______, _______, _______, _______, _______,     _______,             _______, KC_DOWN, _______, _______, _______, _______, \
           KC_VOLD, KC_VOLU, _______, _______,      KC_DELT,                 KC_ENT,               KC_HOME, KC_PGDN, KC_PGUP, KC_END
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _LOWER, _LOWER);
}
