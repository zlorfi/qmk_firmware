#include QMK_KEYBOARD_H

void matrix_init_user(void){
	rgblight_enable();
	rgblight_sethsv(229, 70, 194);
}

//Unicode keymaps
void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

#define DE_AE     UC(0x00E4)
#define DE_SS     UC(0x00DF)
#define DE_OE     UC(0x00F6)
#define DE_UE     UC(0x00FC)
#define DE_AE_CAP UC(0x00C4)
#define DE_OE_CAP UC(0x00D6)
#define DE_UE_CAP UC(0x00DC)
#define DE_EURO   UC(0x20AC)

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
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_NO, KC_RBRC, KC_Z, KC_U, KC_I, KC_O, KC_P, KC_NO,\
		KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_GRV, KC_NO, KC_BSLS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,\
		KC_LSFT, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_SPC, KC_UP, KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,\
		KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_SPC, MO(1), KC_NO, KC_NO, KC_NO\
		),
	[1] = LAYOUT_ortho_5x15(
		KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
		KC_NO, KC_NO, KC_NO, DE_EURO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DE_UE, KC_NO, DE_OE, KC_NO, KC_NO,\
		KC_NO, UC(L'ä'), DE_SS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
		KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,\
		KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO\
		)
};