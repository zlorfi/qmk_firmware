#include QMK_KEYBOARD_H

enum layers {
  _QWERTZ,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
};

enum keycodes {
  QWERTZ = SAFE_RANGE,
  LOWER,
  RAISE,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz
 * ,-----------------------------------------------------------------------------------------------.
 * | Tab   |   Q   |   W   |   E   |   R   |   T   |   Z   |   U   |   I   |   O   |   P   | Bksp  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Esc   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   | '     |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | Shift |   Y   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   | Up    | Enter |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | FN    | Ctrl  | Alt   | GUI   |Lower  |     Space     |Raise  | /     | Left  | Down  | Right |
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTZ] = LAYOUT_planck_mit(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SFTENT,
  FN,      KC_LCTL, KC_LALT, KC_LCMD, LOWER,       KC_SPC,       RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   | Del   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |   _   |   +   |   {   |   }   |   |   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |       |       |       | Vol+  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       | Next  | Vol-  | Play  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_VOLU, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |    `  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   | Del   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |   4   |   5   |   6   |       |       |       |   -   |   =   |   [   |   ]   |   \   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |   7   |   8   |   9   |       |       |       |       |       |       | Vol+  |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |   0   |       |               |       |       | Next  | Vol-  | Play  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
  _______, _______, _______, KC_0,    _______,     _______,      _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------------------.
 * |       | Reset |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | RGBTo |       |       |       |       | AG no | AG sw |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  RGB_TOG, _______, _______, _______, _______, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

/* Function Layer
 * ,-----------------------------------------------------------------------------------------------.
 * |       | Plain | Blink | Rand  | Rainb |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | RGBTo |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       |       | HUE + | HUE - |
 * `-----------------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_mit(
  XXXXXXX, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_HUD
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_FN);
        // update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}