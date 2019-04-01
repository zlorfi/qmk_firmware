 /* Copyright 2015-2017 Christon DeWan
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
// #include "xtonhasvim.h"
#include "fancylighting.h"

/************************************
 * states
 ************************************/

#define ___x___ KC_NO

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum keymap_keycodes {
  RAISE = SAFE_RANGE,
  LOWER
};

/************************************
 * keymaps!
 ************************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | Up   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN   | Ctrl | Alt  | GUI  |Lower*|    Space    |Raise*| /    | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 *
 * - Ctrl acts as Esc when tapped.
 * - Holding ; switches to movement layer.
 * - Raise and Lower are one-shot layers.
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_ESC,        KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,        KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,       KC_Y,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   RSFT_T(KC_ENT),
    LSFT(KC_LALT), KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC,      RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RIGHT 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Del |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | Next | Vol- | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Bail |      |      |      |             |      |      |      | Bail |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,     KC_BSPC,
    KC_DEL,  KC_EXLM,     KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,     KC_PIPE,
    _______, KC_F7,       KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___x___, ___x___, ___x___, ___x___,     KC_ENT,
    _______, TO(_QWERTY), _______, _______, _______,      KC_BSPC,     _______, _______, _______, TO(_QWERTY), ___x___
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Del |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | Next | Vol- | Vol+ | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Bail |      |      |      |             |      |      |      | Bail |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV,  KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,     KC_BSPC,
    KC_DEL,  KC_1,        KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        KC_BSLS,
    _______, KC_F7,       KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___x___, ___x___, ___x___, ___x___,     KC_ENT,
    _______, TO(_QWERTY), _______, _______, _______,     KC_BSPC,      _______, _______, _______, TO(_QWERTY), ___x___
),


/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------.
 * |RGBPlain| Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |--------+------+------+------+------+-------------+------+------+------+------+------|
 * |RGBMode-|      |      |      |      |      |      |      |      |      |      |Lite+ |
 * |--------+------+------+------+------+------|------+------+------+------+------+------|
 * |RGBMode+|      |      |      |      |      |      | Next | Vol- | Vol+ | Play |Lite- |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |  RGB   | Bail |      |      |      |             |      |      |      | Bail |      |
 * `-------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    RGB_MODE_PLAIN,   RESET,       DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______,     KC_DEL,
    RGB_MODE_REVERSE, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,     RGB_VAI,
    RGB_MODE_FORWARD, _______,     _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,     RGB_VAD,
    RGB_TOG,          TO(_QWERTY), _______, _______, _______,     _______,      _______, _______, _______, TO(_QWERTY), ___x___
)
};

#define C_RED 0xFF, 0x00, 0x00
#define C_GRN 0x00, 0xFF, 0x00
#define C_BLU 0x00, 0x00, 0xFF

#define C_YAN 0x00, 0xFF, 0xFF
#define C_PRP 0x7A, 0x00, 0xFF
#define C_ORG 0xFF, 0x93, 0x00

/** Set just 4 LEDs closest to the user. Slightly less annoying to bystanders.*/
void rgbflag(uint8_t r, uint8_t g, uint8_t b, uint8_t rr, uint8_t gg, uint8_t bb) {
  LED_TYPE *target_led = user_rgb_mode ? shadowed_led : led;
  for (int i = 0; i < RGBLED_NUM; i++)  {
    switch (i) {
    case 12: case 13:
      target_led[i].r = r;
      target_led[i].g = g;
      target_led[i].b = b;
      break;
    case 8: case 9:
      target_led[i].r = rr;
      target_led[i].g = gg;
      target_led[i].b = bb;
      break;
    default:
      target_led[i].r = 0;
      target_led[i].g = 0;
      target_led[i].b = 0;
      break;
    }
  }
  rgblight_set();
}

void set_state_leds(void) {
  if (rgblight_get_mode() == 1) {
    switch (biton32(layer_state)) {
    case _RAISE:
      rgbflag(C_BLU, C_GRN);
      break;
    case _LOWER:
      rgbflag(C_BLU, C_RED);
      break;
    case _ADJUST:
      rgbflag(C_BLU, C_PRP);
      break;
    default: //  for any other layers, or the default layer
      rgbflag(C_YAN, C_YAN);
      break;
    }
  }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
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
  }
  return true;
}
