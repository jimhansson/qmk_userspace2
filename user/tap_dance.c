

#include "jimhansson.h"


#ifdef TAP_DANCE_ENABLE
tap_dance_action_t tap_dance_actions[] = {
  [TD_QUOT_DQUO]        = ACTION_TAP_DANCE_DOUBLE(SE_QUOT, SE_DQUO),
  [TD_AT_HASH]          = ACTION_TAP_DANCE_DOUBLE(SE_AT, SE_HASH),
  [TD_QUESTION_EXCLAIM] = ACTION_TAP_DANCE_DOUBLE(SE_QUES, SE_EXLM),
#ifdef REPEAT_KEY_ENABLE
  [TD_REPEAT]           = ACTION_TAP_DANCE_DOUBLE(QK_REPEAT_KEY, QK_ALT_REPEAT_KEY)
#endif
};

#endif // TAP_DANCE_ENABLE
