#ifndef EN_REPLACE_HPP
#define EN_REPLACE_HPP
// vtable 8035f070

#include "Sato/EnemyStrategy.hpp"

class EnReplace : public EnemyStrategy {
public:
    EnReplace() { };
    /* 0x08 */ virtual ~EnReplace();
    /* 0x14 */ virtual bool vt_14();
    /* 0x1C */ virtual void doBehavior();
    /* 0x20 */ virtual void doBehaviorInit();


    bool state_0000_Init();
    bool state_0000_Behavior();
    
    bool state_0010_Init();
    bool state_0010_Behavior();
    
    bool state_0100_Init();
    bool state_0100_Behavior();
};

static EnemyStrategyState enemyStrategyStates[] = {
    EnemyStrategyState(
        0x0000, 
        (EnemyStrategyStateFn)&EnReplace::state_0000_Init, 
        (EnemyStrategyStateFn)&EnReplace::state_0000_Behavior
    ),

    EnemyStrategyState(
        0x0010, 
        (EnemyStrategyStateFn)&EnReplace::state_0010_Init, 
        (EnemyStrategyStateFn)&EnReplace::state_0010_Behavior
    ),

    EnemyStrategyState(
        0x0200, 
        (EnemyStrategyStateFn)&EnReplace::state_0100_Init, 
        (EnemyStrategyStateFn)&EnReplace::state_0100_Behavior
    ),
};



#endif
