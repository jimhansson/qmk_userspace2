
#include "jimhansson.h"
#include "casemodes.h"

// så vi kan speciallisera på tangentbordsnivå
bool __WEAK__ process_record_keymap(uint16_t keycode, keyrecord_t *record) {return true;};


bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if(!process_case_modes(keycode, record)) {
    return false; // else I get both the sep and a space.
  }
  
  switch(keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  case EXT_CFG:
    if (record->event.pressed) {
      layer_off(_CFG);
      return false;
      break;
    }
  case GAME_ON:
    // disables things that are in the way in games
    if(record->event.pressed) {
      if(get_autoshift_state())
	autoshift_disable();
      if(is_combo_enabled())
	combo_disable();
#ifdef KEY_OVERRIDE_ENABLE
      if(key_override_is_enabled())
	key_override_off();
#endif
    }
    break;
  case CAS_TOG:
    if(record->event.pressed) {
      toggle_caps_word();
    }
    break;
  default:
    // pass on to keymap.
    return process_record_keymap(keycode, record);
  }
  return true;
}
