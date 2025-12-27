#pragma once

// Planck-specifika inställningar
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// Autoshift (om aktiverat)
#ifdef AUTO_SHIFT_ENABLE
#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA
#endif

// Combo-inställningar
#ifdef COMBO_ENABLE
#define COMBO_TERM 30
#define COMBO_MUST_HOLD_MODS
#endif

// Leader key
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
