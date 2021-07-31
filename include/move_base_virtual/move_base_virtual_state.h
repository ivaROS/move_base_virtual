#ifndef NAV_MOVE_BASE_VIRTUAL_STATE_H_
#define NAV_MOVE_BASE_VIRTUAL_STATE_H_

namespace move_base_virtual{
  enum MoveBaseVirtualState {
    WAITING,
    PLANNING,
    FOLLOWING,
    CONTROLLING,
    CLEARING
  };
  
  enum RecoveryVirtualTrigger
  {
    PLANNING_R,
    FOLLOWING_R,
    CONTROLLING_R,
    OSCILLATION_R
  };
}

#endif
