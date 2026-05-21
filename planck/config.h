#pragma once

// Planck-specifika inställningar
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

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

