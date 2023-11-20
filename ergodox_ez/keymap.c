
#include QMK_KEYBOARD_H

#include "jimhansson.h"


#define QOUT_SYM LT(_SYM, SE_QUOT)

// clang format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_jimhansson_ergodox_pretty(
  // left hand                                                                                        // right hand
  //╭─────────┬────────┬────────┬────────┬────────┬────────┬────────╮                                 ╭────────┬────────┬────────┬────────┬────────┬─────────┬────────╮
      KC_ESC ,              ___5NUMROW_SFT_L___           ,  KC_NO,                                     KC_NO,              ___5NUMROW_SFT_1___             , SE_PLUS,
  //├─────────┼────────┼────────┼────────┼────────┼────────┼────────┤                                 ├────────┼────────┼────────┼────────┼────────┼─────────┼────────┤
      REP_TD ,              ___5QWERTY_1_L___             ,  KC_NO,	                                KC_NO,              ___6QWERTY_1_R___                        ,
  //├─────────┼────────┼────────┼────────┼────────┼────────┼────────┤                                 ├────────┼────────┼────────┼────────┼────────┼─────────┼────────┤
      QK_LEAD,              ___5QWERTY_2_L___             ,	       		                                            ___6QWERTY_2_R___                        ,  
  //├─────────┼────────┼────────┼────────┼────────┼────────┼────────┤                                 ├────────┼────────┼────────┼────────┼────────┼─────────┼────────┤
      SC_LSPO,              ___5QWERTY_3_L___             ,  ALL_T(KC_NO),                         MEH_T(KC_NO),            ___5QWERTY_3_R___                , SC_RSPC,
  //├─────────┼────────┼────────┼────────┼────────┼────────┴────────╯                                 ╰────────┴────────┼────────┼────────┼────────┼─────────┼────────┤
      QOUT_SYM,SE_ACUT, KC_NO,   KC_LEFT, KC_NO,				                                          KC_NO,  KC_DOWN, SE_CIRC,  SE_ASTR, TT(_SYM),
  //╰─────────┴────────┴────────┴────────┴────────╯                                                                     ╰────────┴────────┴────────┴─────────┴────────╯
  //
  //                                                       ╭────────┬────────╮               ╭────────┬────────╮
                                                      ALT_T(KC_APP),  KC_LGUI,	               KC_ALGR, CTL_T(KC_ESC),
  //                                              ╭────────┼────────┼────────┤               ├────────┼────────┼────────╮
                                                                      KC_HOME,	               KC_PGUP,
  //                                              |        |        ├────────┤               ├────────┤        |        |
                                                    KC_ENT,  KC_BSPC,  KC_END,                 KC_PGDN, KC_TAB,  KC_SPC
  //                                              ╰────────┴────────┴────────╯               ╰────────┴────────┴────────╯
  ),

  [_SYM] = LAYOUT_jimhansson_ergodox_pretty(
  // left hand                                                                                        // right hand
  //╭─────────┬────────┬────────┬────────┬────────┬────────┬────────╮                                 ╭────────┬────────┬────────┬────────┬────────┬─────────┬────────╮
      KC_ESC ,              ___5NUMROW_SFT_L___           ,   KC_NO,                                    KC_NO,              ___5NUMROW_SFT_1___             ,  SE_PLUS,
  //├─────────┼────────┼────────┼────────┼────────┼────────┼────────┤                                 ├────────┼────────┼────────┼────────┼────────┼─────────┼────────┤
      REP_TD ,              ___5SYM_OLD_1_L___             ,  KC_NO,	                                KC_NO,   AT_TD,         ___3NUM_1___       , KC_PAST , KC_PEQL,
  //├─────────┼────────┼────────┼────────┼────────┼────────┼────────┤                                 ├────────┼────────┼────────┼────────┼────────┼─────────┼────────┤
      AMP_TD ,              ___5SYM_OLD_2_L___             ,	       		                                 QOUT_TD,       ___3NUM_2___       , KC_PPLS , KC_PMNS,  
  //├─────────┼────────┼────────┼────────┼────────┼────────┼────────┤                                 ├────────┼────────┼────────┼────────┼────────┼─────────┼────────┤
      QUES_TD,              ___5SYM_OLD_3_L___             , _______,                                  _______,  KC_P0          ___3NUM_3___       , KC_PSLS , KC_PDOT,
  //├─────────┼────────┼────────┼────────┼────────┼────────┴────────╯                                 ╰────────┴────────┼────────┼────────┼────────┼─────────┼────────┤
       _______, _______, _______, _______, _______,				                                          _______, _______, _______, _______ , _______,
  //╰─────────┴────────┴────────┴────────┴────────╯                                                                     ╰────────┴────────┴────────┴─────────┴────────╯
  //
  //                                                       ╭────────┬────────╮               ╭────────┬────────╮
                                                      ALT_T(KC_APP),  KC_LGUI,	               KC_ALGR, CTL_T(KC_ESC),
  //                                              ╭────────┼────────┼────────┤               ├────────┼────────┼────────╮
                                                                      KC_HOME,	               KC_PGUP,
  //                                              |        |        ├────────┤               ├────────┤        |        |
                                                    KC_ENT,  KC_BSPC,  KC_END,                 KC_PGDN, KC_TAB,  KC_SPC
  //                                              ╰────────┴────────┴────────╯               ╰────────┴────────┴────────╯
 
  )
;

