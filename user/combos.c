
#include QMK_KEYBOARD_H

#include "jimhansson.h"

// RIGHT
// R3
const uint16_t PROGMEM io_combo[] = {SE_I, SE_O, COMBO_END};
// R2
const uint16_t PROGMEM jk_combo[] = {SE_J, SE_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {SE_K, SE_L, COMBO_END};
//const uint16_t PROGMEM lö_combo[] = {SE_L, SE_Ö, COMBO_END};
// R1
const uint16_t PROGMEM dot_combo[] = {SE_DOT, SE_COMM, COMBO_END};

// LEFT
// R3
const uint16_t PROGMEM we_combo[] = {SE_W, SE_E, COMBO_END};
// R2
//const uint16_t PROGMEM as_combo[] = {SE_A, SE_S, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {SE_S, SE_D, COMBO_END};
const uint16_t PROGMEM df_combo[] = {SE_D, SE_F, COMBO_END};
// R1
const uint16_t PROGMEM xc_combo[] = {SE_X, SE_C, COMBO_END};


combo_t key_combos[] = {
  COMBO(io_combo, KC_INSERT),
  COMBO(jk_combo, OSM(MOD_RCTL)),
  COMBO(kl_combo, OSM(MOD_RALT)),
  //COMBO(dot_combo, ),
  COMBO(we_combo, KC_DELETE),
  COMBO(sd_combo, OSM(MOD_LALT)),
  COMBO(df_combo, OSM(MOD_LCTL)),
  //COMBO(xc_combo, )
};

// mainly use combos to avoid having to leave homerow to use
// modifiers, will use one-shot-modifiers for that

// med denna kanske jag inte behöver använda mig av oneshot_mods utan
// istället sköter combo det för mig
//#define COMBO_MUST_HOLD_MODS

// - COMBO_TERM_PER_COMBO
//   uint16_t get_combo_term(uint16_t index, combo_t *combo)
//   Optional per-combo timeout window. (default: COMBO_TERM)
// - COMBO_MUST_HOLD_PER_COMBO
//   bool get_combo_must_hold(uint16_t index, combo_t *combo)
//   Controls if a given combo should fire immediately on tap or if it needs to be held. (default: false)
// - COMBO_MUST_TAP_PER_COMBO
//   bool get_combo_must_tap(uint16_t index, combo_t *combo)
//   Controls if a given combo should fire only if tapped within COMBO_HOLD_TERM. (default: false)
// - COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
//   bool get_combo_must_press_in_order(uint16_t index, combo_t *combo)
//   Controls if a given combo should fire only if its keys are pressed in order. (default: true)

    /* OSM(mod) - Momentarily hold down mod. You must use the MOD_* keycodes as shown in Mod Tap, not the KC_* codes. */
    /* OSL(layer) - momentary switch to layer. */
    /* OS_ON - Turns on One Shot keys. */
    /* OS_OFF - Turns off One Shot keys. OSM act as regular mod keys, OSL act like MO. */
    /* OS_TOGG - Toggles the one shot key status. */
/*
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Disable combo `SOME_COMBO` on layer `_LAYER_A`
    switch (combo_index) {
        case SOME_COMBO:
            if (layer_state_is(_LAYER_A)) {
                return false;
            }
    }

    return true;
}
*/

// #define COMBO_ONLY_FROM_LAYER _LAYER_A


// Normally, the timer is started on the first key press and then
// reset on every subsequent key press within the
// COMBO_TERM. Inputting combos is relaxed like this, but also
// slightly more prone to accidental misfires. 

// The next two options alter the behaviour of the timer.
// #define COMBO_STRICT_TIMER

// With COMBO_STRICT_TIMER, the timer is started only on the first key
// press. Inputting combos is now less relaxed; you need to make sure
// the full chord is pressed within the COMBO_TERM. Misfires are less
// common but if you type multiple combos fast, there is a chance that
// the latter ones might not activate properly.

//#define COMBO_NO_TIMER

// By defining COMBO_NO_TIMER, the timer is disabled completely and
// combos are activated on the first key release. This also disables
// the “must hold” functionalities as they just wouldn’t work at all.




  
