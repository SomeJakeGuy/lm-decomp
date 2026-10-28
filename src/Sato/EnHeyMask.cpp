#include "Sato/EnHeyMask.hpp"
#include "macros.h"

dummy_float_data()
enemies_float_data()

static EnemyStrategyState enemiesStatesMask[6] = {
    {
        0, 
        (EnemyStrategyStateFn)&EnHeyMask::state_0_Init, 
        (EnemyStrategyStateFn)&EnHeyMask::state_0_Behavior
    },

    {
        1, 
        (EnemyStrategyStateFn)&EnHeyMask::state_1_Init, 
        (EnemyStrategyStateFn)&EnHeyMask::state_1_Behavior
    },

    {
        2, 
        (EnemyStrategyStateFn)&EnHeyMask::state_2_Init, 
        (EnemyStrategyStateFn)&EnHeyMask::state_2_Behavior
    }, 

    {
        3, 
        (EnemyStrategyStateFn)&EnHeyMask::state_3_Init, 
        (EnemyStrategyStateFn)&EnHeyMask::state_3_Behavior
    },

    {
        4, 
        (EnemyStrategyStateFn)&EnHeyMask::state_4_Init, 
        (EnemyStrategyStateFn)&EnHeyMask::state_4_Behavior
    },

    {
        5, 
        (EnemyStrategyStateFn)&EnHeyMask::state_5_Init, 
        (EnemyStrategyStateFn)&EnHeyMask::state_5_Behavior
    },
};


static EnemyStrategyState enemiesStatesZenmai[2] = {
    {
        0, 
        (EnemyStrategyStateFn)&EnZenmai::state_0_Init, 
        (EnemyStrategyStateFn)&EnZenmai::state_0_Behavior
    },

    {
        4, 
        (EnemyStrategyStateFn)&EnZenmai::state_4_Init, 
        (EnemyStrategyStateFn)&EnZenmai::state_4_Behavior
    },
};

inline EnemyStrategyState* findStateMask(u16 index) {
    for (   
        EnemyStrategyState* state = &enemiesStatesMask[0]; 
        state != &enemiesStatesMask[ARRAY_COUNT(enemiesStatesMask)];
        state++) {

        if (state->mStateIndex == index) {
            return state;
        }
    }

    return nullptr;
}


void EnHeyMask::doBehavior() {
    EnemyStrategyState* state = findStateMask(mCurrentState);

    if (state != nullptr) {
        (this->*state->mBehaviorFunc)();
    }
}

void EnHeyMask::doBehaviorInit() {
    EnemyStrategyState* state = findStateMask(mCurrentState);

    if (state != nullptr) {
        (this->*state->mBehaviorInitFunc)();
    }
}

void EnHeyMask::vt_08() {

}

bool EnHeyMask::state_0_Init() {
    return true;
}

bool EnHeyMask::state_0_Behavior() {
    return true;
}

bool EnHeyMask::state_1_Init() {
    return true;
}

bool EnHeyMask::state_1_Behavior() {
    return true;
}

bool EnHeyMask::state_2_Init() {
    return true;
}

bool EnHeyMask::state_2_Behavior() {
    return true;
}

bool EnHeyMask::state_4_Init() {
    return true;
}

bool EnHeyMask::state_4_Behavior() {
    return true;
}

bool EnHeyMask::state_3_Init() {
    return true;
}

bool EnHeyMask::state_3_Behavior() {
    return true;
}

bool EnHeyMask::state_5_Init() {
    return true;
}

bool EnHeyMask::state_5_Behavior() {
    return true;
}


void EnHeyMask::EnHeyMask_fn_800C6270() {

}

void EnHeyMask::EnHeyMask_fn_800C62DC() {

}

void EnZenmai::doBehavior() {

}

void EnZenmai::doBehaviorInit() {

}


bool EnZenmai::state_0_Init() {
    return true;
}

bool EnZenmai::state_0_Behavior() {
    return true;
}

bool EnZenmai::state_4_Init() {
    return true;
}

bool EnZenmai::state_4_Behavior() {
    return false;
}


void EnZenmai::EnHeyMask_fn_800C6270() {

}

void EnZenmai::EnHeyMask_fn_800C62DC() {

}



void EnHeySpear::doBehavior() {

}
