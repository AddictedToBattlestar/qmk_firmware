#include QMK_KEYBOARD_H

// Layer shorthand
enum layer {
  _BASE,
  _LOWER,
  _RAISE,
  _FN
};

#define LOWER MO(1)
#define RAISE MO(2)
#define FN    MO(3)

// Mac sleep
#define __SLEEP S(LCTL(KC_POWER))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_hhkb(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    RGB_TOG,     RGB_MOD,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELT, \
  KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,     KC_EQL,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,     KC_RBRC,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LSFT(KC_F6), LALT(LGUI(KC_M)), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
           KC_LGUI, KC_LALT, KC_LCTL, LOWER,       KC_BSPC,              KC_SPC,                RAISE,   KC_MUTE, KC_DOWN, KC_UP
  ),

  [_LOWER] = LAYOUT_ortho_hhkb(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,             LALT(LGUI(KC_R)),    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  _______, _______, _______, _______, _______, _______, _______,             _______,             _______, KC_PGUP, _______, _______, _______, KC_F12,  \
  _______, _______, _______, _______, _______, _______, LSFT(LGUI(KC_LBRC)), LSFT(LGUI(KC_RBRC)), KC_HOME, _______, KC_END,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,             _______,             _______, KC_PGDN, _______, _______, _______, _______, \
           _______, _______, _______, _______,      KC_DELT,         KC_ENT,                               _______, _______, KC_HOME, KC_END
  ),

  [_RAISE] = LAYOUT_ortho_hhkb(
  _______, _______, _______, _______, _______, _______, _______,             _______,             _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______,   KC_UP, _______, _______,             _______,             _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_LEFT, _______, KC_RGHT, LSFT(LGUI(KC_LBRC)), LSFT(LGUI(KC_RBRC)), _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_DOWN, _______, _______,             _______,             _______, _______, _______, _______, _______, _______, \
           _______, _______, _______, _______,      KC_DELT,         KC_ENT,                               _______, _______, _______, _______
  ),

  [_FN] = LAYOUT_ortho_hhkb(
  _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_MPRV, KC_MNXT, _______, RGB_SAI, RGB_HUI, _______, _______, _______, _______, _______, _______, \
  _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______, RGB_SAD, RGB_HUD, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, \
           _______, _______, _______, _______,      KC_DELT,         KC_ENT,       _______, _______, _______, RESET
  )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _FN);
}