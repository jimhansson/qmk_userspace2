
#pragma once



// Fix Space Cadet keys for swedish layout
#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8
#define RSPC_KEYS KC_RSFT, KC_RSFT, KC_9



// make sure we can press as many buttons as possible at the same time.
#define FORCE_NKRO

// auto shift //
// if we want to auto-shift anything else than the alphas,
// we will do that in the keymap instead.
//#define AUTO_SHIFT_TIMEOUT 175
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_SPECIAL
#define AUTO_SHIFT_REPEAT

// leader keyconf
#define LEADER_TIMEOUT 250
#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
