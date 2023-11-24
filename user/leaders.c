
#include "jimhansson.h"


#include "casemodes.h"

#define LEAD_D SE_D
#define LEAD_U SE_U
#define LEAD_V SE_V
#define LEAD_X SE_X
#define LEAD_Z SE_Z

#define LEAD_AS    SE_A, SE_S
#define LEAD_BOOT  SE_B, SE_O, SE_O, SE_T
#define LEAD_CAP   SE_C, SE_A, SE_P
#define LEAD_CONF  SE_C, SE_O, SE_N, SE_F
#define LEAD_ESC   SE_E, SE_S, SE_C
#define LEAD_F     SE_F
#define LEAD_NUM   SE_N, SE_U, SE_M
#define LEAD_RESET SE_R, SE_E, SE_S, SE_E, SE_T
#define LEAD_SCRL  SE_S, SE_C, SE_R, SE_L

void leader_end_user(void) {
  //bool did_leader_succeed = false;

  // x-case things
  if(       leader_sequence_one_key(LEAD_U)) {
    enable_xcase_with(SE_UNDS);
    //did_leader_succeed = true;
  } else if(leader_sequence_one_key(LEAD_Z)) { //same place on my symtable
    enable_xcase_with(SE_SLSH);
    //did_leader_succeed = true;s
  } else if(leader_sequence_one_key(SE_COMM)) {
    enable_xcase_with(SE_COMM);
    //did_leader_succeed = true;
  } else if(leader_sequence_one_key(SE_DOT)) {
    enable_xcase_with(SE_DOT);
    //did_leader_succeed = true;
  } else if(leader_sequence_one_key(LEAD_V)) {  // same place on my symtable
    enable_xcase_with(SE_BSLS);
    //did_leader_succeed = true;
  } else if(leader_sequence_one_key(LEAD_D)) {
    // easier to write defines.
    enable_xcase_with(SE_UNDS);
    enable_caps_word();
    //did_leader_succeed = true;
  } else if(leader_sequence_one_key(LEAD_X)) {
    // x-case
    enable_xcase();
    //did_leader_succeed = true;

    // end of x-case things
  } else if(leader_sequence_two_keys(LEAD_AS)){ // AS
    // autoshift toggle
    autoshift_toggle();
    //did_leader_succeed = true;
  } else if(leader_sequence_four_keys(LEAD_BOOT)) { // CONF
    // FIXME
    //did_leader_succeed = true;
  } else if(leader_sequence_three_keys(LEAD_CAP)) { // CAP
    // cap = Caps lock
    register_code(KC_CAPS_LOCK);
    unregister_code(KC_CAPS_LOCK);
    //did_leader_succeed = true;
  } else if(leader_sequence_four_keys(LEAD_CONF)) { // CONF
    // switch to layer for configuration
    layer_on(_CFG);
    //did_leader_succeed = true;
  } else if(leader_sequence_three_keys(LEAD_ESC)) { // ESC
    // ESC = escape key
    register_code(KC_ESC);
    unregister_code(KC_ESC);
    //did_leader_succeed = true;
  } else if(leader_sequence_one_key(LEAD_F)) {
    set_oneshot_layer(_FUN, ONESHOT_START);
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    //did_leader_succeed = true;
  } else if(leader_sequence_three_keys(LEAD_NUM)) { // NUM
    // num = num lock
    register_code(KC_NUM_LOCK);
    unregister_code(KC_NUM_LOCK);
    //did_leader_succeed = true;
  } else if(leader_sequence_five_keys(LEAD_RESET)) {
    reset_keyboard();
    //did_leader_succeed = true;
  } else if(leader_sequence_four_keys(LEAD_SCRL)) {
    // scrl = scroll lock
    register_code(KC_SCROLL_LOCK);
    unregister_code(KC_SCROLL_LOCK);
    //did_leader_succeed = true;
  } 
  
}
