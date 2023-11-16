
#include QMK_KEYBOARD_H

#include "jimhansson.h"


#define QOUT_SYM LT(_SYM, SE_QUOT)

// clang format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |  "   |  #   |  #   |  %   |  L3  |           | L5   |   &  |  /   |  (   |  )   |  =   |  ?     |
 * |        |   1  |  2 @ |  3 £ |  4 $ |  5   |      |           | CMDS |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Delete |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L2  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LEAD   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ö / L2|Ä / Cmd |
 * |        |      |      |      |      |      | Hyper|           | Meh  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Left   |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ;  |   :  |_/Ctrl| RShift |
 * | Shift  |      |      |      |      |      |      |           |      |      |      |   ,  |   .  |-     |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | '/L1 |  `   |AltShf| Left | L2   |                                       |  L2  | Down |  ^   |  *   | ~L1  |
 *   |      |  '   |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | LGui |       | AltGr|Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Enter|Back- |------|       |------|  Tab   |Space |
 *                                 |      |space | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_BASE] = LAYOUT_jimhansson_ergodox_pretty(
  // left hand
  //╭─────────┬────────┬────────┬────────┬────────┬────────┬────────╮                                 ╭────────┬────────┬────────┬────────┬────────┬────────┬────────╮
      XXXXXXX, SE_EXLM, SE_DQUO, SE_HASH, SE_CURR, SE_PERC,   KC_NO,                                   KC_NO,   SE_AMPR, SE_SLSH, SE_LPRN, SE_RPRN,  SE_EQL, SE_PLUS,	  	 
      KC_DEL , SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,      KC_NO,	                               KC_NO,   SE_Y,    SE_U,    SE_I,    SE_O,     SE_P,   SE_ARNG,	   
      QK_LEAD, SE_A,    SE_S,    SE_D,    SE_F,    SE_G,	       		                                SE_H,    SE_J,    SE_K,    SE_L,     ODIANAV,GUI_T(SE_ADIA),  
      SC_LSPO, Z_CTL,   SE_X,    SE_C,    SE_V,    SE_B,      ALL_T(KC_NO),                       MEH_T(KC_NO), SE_N,    SE_M,      SE_COMM,    SE_DOT, CTL_T(SE_MINS),       SC_RSPC,	   
      QOUT_SYM,SE_ACUT, KC_NO,   KC_LEFT, KC_NO,				                                    KC_NO,      KC_DOWN,    SE_CIRC,    SE_ASTR,              TT(_SYM),	   
                                                            ALT_T(KC_APP),       KC_LGUI,	  KC_ALGR,      CTL_T(KC_ESC),								   
                                                                                 KC_HOME,	  KC_PGUP,											   
                                                            KC_ENT,  KC_BSPC,    KC_END,          KC_PGDN,      KC_TAB,  KC_SPC                                                                      
  )
};

