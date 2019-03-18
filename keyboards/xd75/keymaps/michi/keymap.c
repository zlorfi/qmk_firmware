#include QMK_KEYBOARD_H

void matrix_init_user(void){
	rgblight_enable();
	rgblight_sethsv(229, 70, 194);
}

//Unicode keymaps
void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

enum custom_keycodes {
  MAC_AE = SAFE_RANGE,
  MAC_OE,
  MAC_SS,
	MAC_UE,
	MAC_EURO
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case 0:
	    rgblight_sethsv(229, 70, 149);
      break;
    case 1:
      rgblight_setrgb (0x66,  0x66, 0x00);
      break;
    }
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_5x15(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRAVE, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,\
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_QUOT,\
		KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_NO, KC_NO, KC_NO, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,\
		KC_LSFT, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_UP, KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,\
		KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(1), KC_NO, KC_NO, KC_NO\
		),
	[1] = LAYOUT_ortho_5x15(
		KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
		KC_NO, KC_NO, KC_NO, MAC_EURO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MAC_UE, KC_NO, MAC_OE, KC_NO, KC_NO,\
		KC_NO, MAC_AE, MAC_SS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
		KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,\
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