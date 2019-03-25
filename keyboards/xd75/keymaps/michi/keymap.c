#include QMK_KEYBOARD_H
#ifdef UNICODE_ENABLE
  #include "unicode_mac.c"
#endif
#ifndef UNICODE_ENABLE
  #include "unicode_ansi.c"
#endif

#define ___x___ KC_NO
#define _BASE 0
#define _FN 1

void matrix_init_user(void){
	#ifdef RGBLIGHT_ENABLE
		#ifndef LAYER_SWITCH_RGB
			rgblight_enable();
			rgblight_sethsv(229, 70, 194);
			rgblight_mode(2);
		#endif
	#endif
  #ifdef UNICODE_ENABLE
    // go to System Preferences > Keyboard > Input Sources, add Unicode Hex Input
    set_unicode_input_mode(UC_OSX);
  #endif
}

#ifdef RGBLIGHT_ENABLE
  #ifdef LAYER_SWITCH_RGB
		void matrix_scan_user(void) {  // runs frequently to update info
      uint8_t layer = biton32(layer_state); // get current layer
      static uint8_t current_layer; // check historic layer
      static bool has_layer_changed = true;
      // static, so it is kept the same between calls
      // defaults to true, so that it runs once to initially set the light

      if (layer != current_layer) {
        has_layer_changed = true;
        current_layer = layer; // update layer information
      }
      // Check for layer change, and apply color if its changed since last check
      if (has_layer_changed) {
        // change backlight based on layer.  These should be numbers or whatever you defined the layers as
        switch (layer) {
          case _BASE:
            rgblight_sethsv(229, 70, 149);
            break;
          case _FN:
            rgblight_setrgb (0x66,  0x66, 0x00);
            break;
          // default:
          //   rgblight_sethsv(229, 70, 149);
          //   break;
        }
        has_layer_changed = false;
      }
    };
	#endif
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* _BASE
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Z      | U      | I      | O      | P      | '      |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | ESC    | A      | S      | D      | F      | G      |        |        |        | H      | J      | K      | L      | ;      | ENTER  |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | LSHIFT | Y      | X      | C      | V      | B      |        |        |        | N      | M      | ,      | .      | UP     | SHIFEN |
  * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
  * | LCTRL  | LALT   | LGUI   | MO(1)  | SPACE  | SPACE  |        |        |        |        | /      | MO(1)  | LEFT   | DOWN   | RIGHT  |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */
	[_BASE] = LAYOUT_ortho_5x15(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRAVE, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,\
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS,  KC_RBRC, KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,\
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    ___x___, ___x___,  ___x___, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
		KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    ___x___, ___x___,  ___x___, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SFTENT,\
		KC_LCTL, KC_LALT, KC_LGUI, MO(_FN), KC_SPC,  KC_SPC,  ___x___, ___x___,  ___x___, ___x___, KC_SLSH, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT \
		),

  /* _FN
   * .--------------------------------------------------------------------------------------------------------------------------------------.
   * |        | VOL -  | VOL +  | MUTE   |        |        |        |        |        |        |        |        |        |        | DEL    |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        | €      |        |        |        |        |        |        | Ü      |        | Ö      |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        | Ä      | ß      |        |        |        |        |        |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        | RGB_TO |        |        |        |        |        |        |        |        |        |
   * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
   * |        |        |        |        |        |        | KC_MRWD| KC_MPLY| KC_MFFD|        |        |        |        |        |        |
   * '--------------------------------------------------------------------------------------------------------------------------------------'
   */
	[_FN] = LAYOUT_ortho_5x15(
		___x___, KC_VOLD, KC_VOLU, KC_MUTE, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_DEL, \
		___x___, ___x___, ___x___, MAC_EUR, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, MAC_UE,  ___x___, MAC_OE,  ___x___, ___x___,\
		___x___, MAC_AE,  MAC_SS,  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___,\
		_______, ___x___, ___x___, ___x___, ___x___, ___x___, RGB_TOG, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, _______,\
		___x___, ___x___, ___x___, ___x___, ___x___, ___x___, KC_MRWD, KC_MPLY, KC_MFFD, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___ \
		)
};
