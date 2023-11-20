#pragma once

#include "quantum.h"
#include "keymap_swedish.h"


#define __WEAK__ __attribute__((weak))

enum layer_names {
  _BASE,
  _SYM,
  _NAV,
  _CFG
};

enum keycodes {
  EXT_CFG = SAFE_RANGE,
  GAME_ON,
  CAS_TOG,
  ALT_TAB,
};

//använd en combo.def istället.
enum combos {
  CMB_LCTL = 0,
  CMB_RCTL,
  CMB_LALT,
  CMB_RALT,
  CMB_LGUI,
  CMB_RGUI,
  CMB_ESC,
  CMB_INS,
  CMB_DEL,
  CMB_LENGTH
};


#ifdef TAP_DANCE_ENABLE
enum tap_dances {
  TD_QUOT_DQUO,
  TD_AT_TILD,
  TD_QUESTION_EXCLAIM,
  TD_AMPERSAND_CIRCUMFLEX,
  // de som måste få sina egna knappar om inte tap_dance finns är dessa ~,",!,^
  TD_REPEAT
};
#endif

#ifdef TAP_DANCE_ENABLE
  #define QUOT_TD TD(TD_QUOT_DQUO)
  #define AT_TD TD(TD_AT_TILD)
  #define QUES_TD TD(TD_QUESTION_EXCLAIM)
  #define REP_TD TD(TD_REPEAT)
  #define AMP_TD TD(TD_AMPERSAND_CIRCUMFLEX)
#else
  #define QUOT_TD SE_QUOT
  #define AT_TD   SE_AT
  #define QUES_TD SE_QUES
// if we dont have repeat key enabled we will use a REDO instead
#ifdef REPEAT_KEY_ENABLE
  #define REP_TD QK_REP
#else
  #define REP_TD REDO
#endif
  #define AMP_TD KC_AMPERSAND
#endif

//backwards alt_tab
#define TLA_TAB LSFT(ALT_TAB)
//HOLD down Ö
#define ODIANAV LT(_NAV, SE_ODIA)
// pinky ctrl
#define Z_CTL LCTL_T(SE_Z)
#define MINS_CTL RCTL_T(SE_MINS)


/*** base ***/
                         /* ╭────────┬────────┬────────┬────────┬────────╮ */
                         /* │  Q     │  W     │  E     │  R     │  T     │ */
#define ___5QWERTY_1_L___     SE_Q,    SE_W,    SE_E,    SE_R,    SE_T
                         /* ├────────┼────────┼────────┼────────┼────────┤ */
                         /* │  A     │  S     │  D     │  F     │  G     │ */
#define ___5QWERTY_2_L___     SE_A,    SE_S,    SE_D,    SE_F,    SE_G
                         /* ├────────┼────────┼────────┼────────┼────────┤ */
                         /* │  Z     │  X     │  C     │  V     │  B     │ */
#define ___5QWERTY_3_L___     Z_CTL,   SE_X,    SE_C,    SE_V,    SE_B
                         /* ╰────────┴────────┴────────┴────────┴────────╯ */

                         /* ╭────────┬────────┬────────┬────────┬─────────┬────────╮ */
                         /* │  Y     │  U     │  I     │  O     │   P     │  Å     │ */
#define ___6QWERTY_1_R___     SE_Y,    SE_U,    SE_I,    SE_O,     SE_P,    SE_ARNG
                         /* ├────────┼────────┼────────┼────────┼─────────┼────────┤ */
                         /* │  H     │  J     │  K     │  L     │  Ö      │  Ä     │ */
#define ___6QWERTY_2_R___     SE_H,    SE_J,    SE_K,    SE_L,    ODIANAV,  SE_ADIA
                         /* ├────────┼────────┼────────┼────────┼─────────┼────────┤ */
                         /* │  N     │  M     │  ,     │  .     │ -       │          */
#define ___5QWERTY_3_R___     SE_N,    SE_M,   SE_COMM,  SE_DOT,  MINS_CTL
                         /* ╰────────┴────────┴────────┴────────┴─────────╯          */


/*** NUMPAD ***/
                         /* ╭────────┬────────┬─────────╮ */
                         /* │  7     │  8     │  9      │ */
#define ___3NUM_1___          KC_P7,   KC_P8,   KC_P9
                         /* ├────────┼────────┼─────────┤ */
                         /* │  4     │  5     │  6      │ */
#define ___3NUM_2___          KC_P4,   KC_P5,   KC_P6
                         /* ├────────┼────────┼─────────┤ */
                         /* │  1     │  2     │  3      │ */
#define ___3NUM_3___          KC_P1,   KC_P2,   KC_P3 
                         /* ╰────────┴────────┴─────────╯ */


/*** number-row ***/
/*** sfited ***/
                         /* ╭────────┬────────┬────────┬────────┬─────────╮ */
                         /* │  !     │  "     │  #     │  ¤     │   %     │ */
#define ___5NUMROW_SFT_L___  SE_EXLM, SE_DQUO, SE_HASH, SE_CURR, SE_PERC
                         /* ├────────┼────────┼────────┼────────┼─────────┤ */
                         /* │  &     │  /     │  (     │  )     │   =     │ */
#define ___5NUMROW_SFT_R___  SE_AMPR, SE_SLSH, SE_LPRN, SE_RPRN, SE_EQL
                         /* ╰────────┴────────┴────────┴────────┴─────────╯ */
/*** normal ***/
                         /* ╭────────┬────────┬────────┬────────┬─────────╮ */
                         /* │  1     │  2     │  3     │  4     │   5     │ */
#define ___5NUMROW_NOR_L___   KC_1,    KC_2,    KC_3,    KC_4,    KC_5
                         /* ├────────┼────────┼────────┼────────┼─────────┤ */
                         /* │  6     │  7     │  8     │  9     │   0     │ */
#define ___5NUMROW_NOR_R___   KC_6,    KC_7,    KC_8,    KC_9,    KC_0
                         /* ╰────────┴────────┴────────┴────────┴─────────╯ */
/*** alt-gr ***/
                         /* ╭───────────┬───────────┬───────────┬───────────┬────────────╮ */
                         /* │  ¡        │  @        │  £        │  $        │   €        │ */
#define ___5NUMROW_ALT_L___   ALGR(KC_1), ALGR(KC_2), ALGR(KC_3), ALGR(KC_4), ALGR(KC_5)
                         /* ├───────────┼───────────┼───────────┼───────────┼────────────┤ */
                         /* │  ¥        │  {        │  [        │  ]        │   }        │ */
#define ___5NUMROW_ALT_R___   ALGR(KC_6), ALGR(KC_7), ALGR(KC_8), ALGR(KC_9), ALGR(KC_0)
                         /* ╰───────────┴───────────┴───────────┴───────────┴────────────╯ */


/*** my old left swedish symbol-table ***/
                         /* ╭────────┬────────┬────────┬────────┬─────────╮ */
                         /* │  *     │  {     │  }     │  %     │   |     │ */
#define ___5SYM_OLD_1___      SE_ASTR, SE_LCBR, SE_RCBR, SE_PERC, SE_PIPE 
                         /* ├────────┼────────┼────────┼────────┼─────────┤ */
                         /* │  <     │  (     │  )     │  >     │   $     │ */
#define ___5SYM_OLD_2___      SE_LABK, SE_LPRN, SE_RPRN, SE_RABK, SE_DLR
                         /* ├────────┼────────┼────────┼────────┼─────────┤ */
                         /* │  /     │  [     │  ]     │  \     │   #     │ */
#define ___5SYM_OLD_3___      SE_SLSH, SE_LBRC, SE_RBRC, SE_BSLS, SE_HASH
                         /* ╰────────┴────────┴────────┴────────┴─────────╯ */

/*** functions keys ***/
                         /* ╭────────┬────────┬────────┬────────┬─────────┬────────╮ */
                         /* │  F1    │  F2    │  F3    │  F4    │  F5     │  F6    │ */
#define ___6FUNCTI_1_L___     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6
                         /* ├────────┼────────┼────────┼────────┼─────────┼────────┤ */
                         /* │  F7    │  F8    │  F9    │  F10   │  F11    │  F12   │ */
#define ___6FUNCTI_1_R___     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12
                         /* ├────────┼────────┼────────┼────────┼─────────┼────────┤ */
                         /* │  F13   │  F14   │  F15   │  F16   │  F17    │  F18   │ */
#define ___6FUNCTI_2_L___     KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,   KC_F18
                         /* ├────────┼────────┼────────┼────────┼─────────┼────────┤ */
                         /* │  F19   │  F20   │  F21   │  F22   │  F23    │  F24   │ */
#define ___6FUNCTI_2_R___     KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,   KC_F24
                         /* ╰────────┴────────┴────────┴────────┴─────────┴────────╯ */


/*** VIM style nav ***/
                         /* ╭────────┬────────┬────────┬────────╮ */
                         /* │  Left  │  Down  │  Up    │  Right │ */
#define ___4NAV_VIM_2_R___   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
                         /* ├────────┼────────┼────────┼────────┤ */
                         /* │  Home  │  PgDn  │  PgUp  │  End   │ */
#define ___4NAV_VIM_3_R___   KC_HOME, KC_PGDN, KC_PGUP, KC_END
                         /* ╰────────┴────────┴────────┴────────╯ */
                         /* ╭────────┬────────┬────────┬────────╮ */
                         /* │ Mouse L│ Mouse U│ Mouse D│ Mouse U│ */
#define ___4MOUSE_VIM_2_R___  KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R
                         /* ├────────┼────────┼────────┼────────┤ */
                         /* │ Wheel L│ Wheel D│ Wheel U│ Wheel R│ */
#define ___4MOUSE_VIM_3_R___  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R
                         /* ╰────────┴────────┴────────┴────────╯ */
			 
/*** nav ***/
                         /* ╭────────┬────────┬────────┬────────╮ */
                         /* │  PgUp  │  Home  │  Up    │  End   │ */
#define ___4NAV_MY_1___       KC_PGUP, KC_HOME,  KC_UP,   KC_END
                         /* ├────────┼────────┼────────┼────────┤ */
                         /* │  PgDn  │  Left  │  Down  │  Right │ */
#define ___4NAV_MY_2___      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT
                         /* ╰────────┴────────┴────────┴────────╯ */

			 /* ╭─────────┬─────────┬─────────╮ */
                         /* │         │  UP     │         │ */
#define ___3MOUSE_MY_1___     KC_WH_L,  KC_MS_U,  KC_WH_R
                         /* ├─────────┼─────────┼─────────┤ */
                         /* │  LEFT   │  DOWN   │  RIGHT  │ */
#define ___3MOUSE_MY_2___     KC_MS_L,  KC_MS_D,  KC_MS_R
                         /* ╰─────────┴─────────┴─────────╯ */

			 /* ╭─────────┬─────────┬─────────┬─────────╮ */
                         /* │         │         │  UP     │         │ */
#define ___4MOUSE_MY_1___     KC_WH_U,       ___3MOUSE_MY_1___
                         /* ├─────────┼─────────┼─────────┼─────────┤ */
                         /* │         │  LEFT   │  DOWN   │  RIGHT  │ */
#define ___4MOUSE_MY_2___     KC_MS_D,       ___3MOUSE_MY_2___
                         /* ╰─────────┴─────────┴─────────┴─────────╯ */

			 /* ╭─────────┬─────────┬─────────╮ */
                         /* │         │  UP     │         │ */
#define ___3MOUSE_BTN___      KC_BTN1,  KC_BTN3,  KC_BTN2
                         /* ╰─────────┴─────────┴─────────╯ */


/*** config things ***/
			 /* ╭─────────┬─────────┬─────────┬─────────┬─────────╮ */
                         /* │         │         │         │         │         │ */
#define ___5CFG_L_1___        AS_UP   , _______ , _______ , _______ , _______                
                         /* ├─────────┼─────────┼─────────┼─────────┼─────────┤ */
                         /* │         │         │         │         │         │ */
#define ___5CFG_L_2___        AS_TOGG , CM_TOGG , KO_TOGG , CAS_TOG , GAME_ON 
                         /* ├─────────┼─────────┼─────────┼─────────┼─────────┤ */
                         /* │         │         │         │         │         │ */
#define ___5CFG_L_3___        AS_DOWN , _______ , _______ , _______ , _______                
                         /* ╰─────────┴─────────┴─────────┴─────────┴─────────╯ */

/*** Shortcuts ***/
// these migth be intercepted by overrides and instead of sending ctrl+<X>
// will instead send specific codes just for these from extended keyboards.
#define CUT   LCTL(SE_X)
#define COPY  LCTL(SE_C)
#define PASTE LCTL(SE_V)
#define UNDO  LCTL(SE_Z)
#define REDO  LCTL(SE_Y)
                         /* ╭────────┬────────┬────────┬────────┬─────────╮ */
                         /* │  1     │  2     │  3     │  4     │   5     │ */
                         /* │  1     │  2     │  3     │  4     │   5     │ */
#define ___5CLIPBOARD_L___    UNDO,    CUT,     COPY,    PASTE,   REDO
                         /* ├────────┼────────┼────────┼────────┼─────────┤ */
                         /* │  1     │  2     │  3     │  4     │   5     │ */
                         /* │  1     │  2     │  3     │  4     │   5     │ */
#define ___5CLIPBOARD_R___    REDO,    PASTE,   COPY,    CUT,     UNDO
                         /* ╰────────┴────────┴────────┴────────┴─────────╯ */

// homerow modifiers macros
#define HRML(k1,k2,k3,k4)  LCTL_T(k1), LALT_T(k2), LGUI_T(k3), LSFT_T(k4)
#define HRMR(k1,k2,k3,k4)  RSFT_T(k1), RGUI_T(k2), RALT_T(k3), RCTL_T(k4)

#define ___3___ _______, _______, _______
#define ___6___ ___3___, ___3___

// layout macros
#define LAYOUT_jimhansson_planck_grid(...) LAYOUT_planck_grid(__VA_ARGS__)
#define LAYOUT_jimhansson_ergodox_pretty(...) LAYOUT_ergodox_pretty(__VA_ARGS__)
#define LAYOUT_jimhansson_split_3x6_3(...)  LAYOUT_split_3x6_3(__VA_ARGS__)
