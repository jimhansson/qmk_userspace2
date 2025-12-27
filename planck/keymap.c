#include QMK_KEYBOARD_H
#include "jimhansson.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_jimhansson_planck_grid(
        // Rad 1 (QWERTY)
        KC_ESC,  ___5QWERTY_1_L___, ___6QWERTY_1_R___,
        // Rad 2 (QWERTY)
        QK_LEAD, ___5QWERTY_2_L___, ___6QWERTY_2_R___,
        // Rad 3 (QWERTY + Modifiers)
        SC_LSPO, ___5QWERTY_3_L___, ___5QWERTY_3_R___, SC_RSPC,
        // Rad 4 (Navigation + Thumbs)
        TT(_NAV), KC_BSPC, KC_ENT,  KC_SPC,  KC_TAB,  TT(_SYM), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_INS
    ),

    [_SYM] = LAYOUT_jimhansson_planck_grid(
        // Rad 1 (Symboler)
        KC_ESC,  SE_ASTR, SE_LCBR, SE_RCBR, SE_PERC, SE_PIPE, SE_AMPR, SE_SLSH, SE_LPRN, SE_RPRN, SE_EQL,  SE_PLUS,
        // Rad 2 (Numerisk)
        _______, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_PMNS, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PSLS, KC_PDOT,
        // Rad 3 (Symboler + Numerisk)
        _______, SE_LABK, SE_LBRC, SE_RBRC, SE_BSLS, SE_HASH, KC_P1,   KC_P2,   KC_P3,   KC_P0,   _______, _______,
        // Rad 4 (Navigation)
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______
    ),

    [_NAV] = LAYOUT_jimhansson_planck_grid(
        // Rad 1 (Funktioner)
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        // Rad 2 (Mus)
        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_U, KC_WH_D, KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_U, KC_WH_D,
        // Rad 3 (Navigation)
        _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
        // Rad 4 (Clipboard)
        _______, _______, _______, _______, _______, _______, UNDO,    CUT,     COPY,    PASTE,   REDO,    _______
    ),

    [_CFG] = LAYOUT_jimhansson_planck_grid(
        // Rad 1 (Konfiguration)
        _______, AS_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // Rad 2 (Toggles)
        _______, AS_TOGG, CM_TOGG, KO_TOGG, CAS_TOG, GAME_ON, _______, _______, _______, _______, _______, _______,
        // Rad 3 (Reset)
        _______, AS_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // Rad 4 (Exit)
        EXT_CFG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUN] = LAYOUT_jimhansson_planck_grid(
        // Rad 1 (F13-F24)
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,
        // Rad 2 (Media)
        _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, _______, _______, _______, KC_F24,
        // Rad 3 (System)
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // Rad 4 (Bootloader)
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT
    )
};
