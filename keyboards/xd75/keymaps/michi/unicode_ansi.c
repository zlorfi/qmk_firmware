enum custom_keycodes {
  MAC_AE = SAFE_RANGE,
  MAC_OE,
  MAC_SS,
  MAC_UE,
  MAC_EUR
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
      case MAC_EUR:
        SEND_STRING(SS_LALT("@"));
        return false;
      case MAC_SS:
        SEND_STRING(SS_LALT("s"));
        return false;
    }
  }
  return true;
};