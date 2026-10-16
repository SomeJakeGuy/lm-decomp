
#include "Koga/EnCircleMove.hpp"
#include "Koga/EnChase.hpp"
#include "macros.h"

dummy_float_data()
enemies_float_data()

// I'm assuming its CircleMove for now since the function is labelled before EnChase first functions
static EnemyStrategyState enemiesStatesCircleMove[1] = {
    {
        0, 
        (EnemyStrategyStateFn)&EnCircleMove::state_0_Init, 
        (EnemyStrategyStateFn)&EnCircleMove::state_0_Behavior
    },
};

void EnCircleMove::doBehavior() {

}

void EnCircleMove::doBehaviorInit() {

}

bool EnCircleMove::state_0_Init() {
    return true;
}

bool EnCircleMove::state_0_Behavior() {
    return true;
}

EnChase::EnChase() {

}

EnCircleMove::~EnCircleMove() {
    
}

// EnChase
static EnemyStrategyState enemiesStatesChase[3] = {
    {
        0, 
        (EnemyStrategyStateFn)&EnChase::state_0_Init, 
        (EnemyStrategyStateFn)&EnChase::state_0_Behavior
    },

    {
        1, 
        (EnemyStrategyStateFn)&EnChase::state_1_Init, 
        (EnemyStrategyStateFn)&EnChase::state_1_Behavior
    },

    {
        2, 
        (EnemyStrategyStateFn)&EnChase::state_2_Init, 
        (EnemyStrategyStateFn)&EnChase::state_2_Behavior
    },
};

void EnChase::doBehavior() {

}

void EnChase::doBehaviorInit() {

}

bool EnChase::state_0_Init() {
    return true;
}

bool EnChase::state_0_Behavior() {
    return true;
}

bool EnChase::state_1_Init() {
    return true;
}

bool EnChase::state_1_Behavior() {
    return true;
}

bool EnChase::state_2_Init() {
    return true;
}

bool EnChase::state_2_Behavior() {
    return true;
}
