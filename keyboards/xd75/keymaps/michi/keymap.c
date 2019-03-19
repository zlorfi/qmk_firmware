#include QMK_KEYBOARD_H

void matrix_init_user(void){
	#ifdef RGBLIGHT_ENABLE 
		#ifndef LAYER_SWITCH_RGB
			rgblight_enable();
			rgblight_sethsv(229, 70, 194);
			rgblight_mode(2);
		#endif
	#endif
}

//Unicode keymaps
// void eeconfig_init_user(void) {
//   set_unicode_input_mode(UC_OSX);
// }

enum custom_keycodes {
  MAC_AE = SAFE_RANGE,
  MAC_OE,
  MAC_SS,
	MAC_UE,
	MAC_EURO
};

#ifdef RGBLIGHT_ENABLE 
  #ifdef LAYER_SWITCH_RGB
		void matrix_scan_user(void)
		{  // runs frequently to update info
				uint8_t layer = biton32(layer_state); // get current layer
				static uint8_t current_layer; // check historic layer
				static bool has_layer_changed = true;
				// static, so it is kept the same between calls
				// defaults to true, so that it runs once to initially set the light

				if (layer != current_layer)
				{
						has_layer_changed = true;
						current_layer = layer; // update layer information
				}
				// Check for layer change, and apply color if its changed since last check
				if (has_layer_changed)
				{
						// change backlight based on layer.  These should be numbers or whatever you defined the layers as
						switch (layer)
						{
								case 0:
									rgblight_sethsv(229, 70, 149);
									break;
								case 1:
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
	[0] = LAYOUT_ortho_5x15(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRAVE, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,\
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_QUOT,\
		KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_NO, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,\
		KC_LSFT, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_UP, KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,\
		KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(1), KC_NO, KC_NO, KC_NO\
		),
	[1] = LAYOUT_ortho_5x15(
		KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,\
		KC_NO, KC_NO, KC_NO, MAC_EURO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MAC_UE, KC_NO, MAC_OE, KC_NO, KC_NO,\
		KC_NO, MAC_AE, MAC_SS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
		KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,\
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO\
		)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case MAC_UE:
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
          SEND_STRING(SS_LALT("u") SS_LSFT("u"));
        } else {
				  SEND_STRING(SS_LALT("u")"u");
        }
				return false;
      case MAC_AE:
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
				  SEND_STRING(SS_LALT("u") SS_LSFT("a"));
        } else {
          SEND_STRING(SS_LALT("u")"a");
        }
        return false;
      case MAC_OE:
        if(keyboard_report->mods & MOD_BIT(KC_LSFT)) {
          clear_keyboard();
          SEND_STRING(SS_LALT("u") SS_LSFT("o"));
        } else {
          SEND_STRING(SS_LALT("u")"o");
        }
        return false;
      case MAC_EURO:
				SEND_STRING(SS_LALT("@"));
        return false;
      case MAC_SS:
        SEND_STRING(SS_LALT("s"));
        return false;
		}
	}
	return true;
};