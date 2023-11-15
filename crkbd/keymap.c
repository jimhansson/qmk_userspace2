/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "jimhansson.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_jimhansson_split_3x6_3(
  //╭────────┬────────┬────────┬────────┬────────┬────────╮                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
      REP_TD ,    ___5QWERTY_1_L___                       ,                         ___6QWERTY_1_R___                                ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
      QK_LEAD,    ___5QWERTY_2_L___                       ,                         ___6QWERTY_2_R___                                ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
      SC_LSPO,    ___5QWERTY_3_L___                       ,                         ___5QWERTY_3_R___                       , SC_RSPC,
  //╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮  ╭────────┼────────┼────────┼────────┴────────┴────────┴────────╯
                                         TT(_NAV), KC_BSPC, KC_ENT,     KC_SPC,  KC_TAB,  TT(_SYM)
                                      //╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯

  ),

    [_SYM] = LAYOUT_jimhansson_split_3x6_3(
  //╭────────┬────────┬────────┬────────┬────────┬────────╮                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
      KC_ESC ,     ___5SYM_OLD_1___                       ,                      AT_TD  ,       ___3NUM_1___       , KC_PAST, KC_PEQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
      AMP_TD ,     ___5SYM_OLD_2___                       ,                      QUOT_TD,       ___3NUM_2___       , KC_PPLS, KC_PMNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     QUES_TD ,     ___5SYM_OLD_3___                       ,                      KC_P0  ,       ___3NUM_3___       , KC_PSLS, KC_PDOT,
  //╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮  ╭────────┼────────┼────────┼────────┴────────┴────────┴────────╯
                                         _______, _______,  _______,    _______, _______, _______ 
                                      //╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯

  ),

    [_NAV] = LAYOUT_jimhansson_split_3x6_3(
  //╭────────┬────────┬────────┬────────┬────────┬────────╮                    ╭────────┬────────┬────────┬────────┬────────┬────────╮
      KC_ESC ,     ___4MOUSE_MY_1___             , _______,                            ___4NAV_MY_1___             , _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,     ___4MOUSE_MY_2___             , _______,                            ___4NAV_MY_2___             , _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                    ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ , _______,     ___3MOUSE_BTN___     , _______,                            ___5CLIPBOARD_R___                   , _______,
  //╰────────┴────────┴────────┴────────┼────────┼────────┼────────╮  ╭────────┼────────┼────────┼────────┴────────┴────────┴────────╯
                                          _______, KC_BTN2, KC_BTN1,    _______, _______, _______ 
                                      //╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯
  )
};

