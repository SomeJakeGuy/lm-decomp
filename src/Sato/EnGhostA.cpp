#include "Sato/EnGhostA.hpp"
#include "Sato/EnRotation.hpp"
#include "macros.h"

dummy_float_data()
enemies_float_data()

static EnemyStrategyState enemiesStates[0xC] = {
    {
        0, 
        (EnemyStrategyStateFn)&EnGhostA::state_0_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_0_Behavior
    },

    {
        0xB, 
        (EnemyStrategyStateFn)&EnGhostA::state_B_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_B_Behavior
    },

    {
        1, 
        (EnemyStrategyStateFn)&EnGhostA::state_1_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_1_Behavior
    },

    {
        2, 
        (EnemyStrategyStateFn)&EnGhostA::state_2_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_2_Behavior
    },

    {
        3, 
        (EnemyStrategyStateFn)&EnGhostA::state_3_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_3_Behavior
    },

    {
        4, 
        (EnemyStrategyStateFn)&EnGhostA::state_4_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_4_Behavior
    },

    {
        5, 
        (EnemyStrategyStateFn)&EnGhostA::state_5_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_5_Behavior
    },

    {
        6, 
        (EnemyStrategyStateFn)&EnGhostA::state_6_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_6_Behavior
    },

    {
        7, 
        (EnemyStrategyStateFn)&EnGhostA::state_7_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_7_Behavior
    },

    {
        8, 
        (EnemyStrategyStateFn)&EnGhostA::state_8_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_8_Behavior
    },

    {
        9, 
        (EnemyStrategyStateFn)&EnGhostA::state_9_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_9_Behavior
    },

    {
        0xA, 
        (EnemyStrategyStateFn)&EnGhostA::state_A_Init, 
        (EnemyStrategyStateFn)&EnGhostA::state_A_Behavior
    },
};

EnGhostA::EnGhostA() {

}


EnRotationFar::~EnRotationFar() {

}

EnRotationNear::~EnRotationNear() {
    
}



void EnGhostA::doBehavior() {

}

void EnGhostA::doBehaviorInit() {

}

bool EnGhostA::vt_14() {
    return false;
}


bool EnGhostA::onCollideWithPlayer(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onSprayedWithFire(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onSprayedWithIce(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onSprayedWithWater(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onEnteredFlashlightBeam(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::vt_18(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onFishingBegin(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onCaptureBegin(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onPlayerLeftRoom(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::onPlayerEnteredRoom(Koga::CharacterEvent* msg) {
    return true;
}

bool EnGhostA::state_0_Init() {
    return true;
}

bool EnGhostA::state_0_Behavior() {
    return true;
}

bool EnGhostA::state_1_Init() {
    return true;
}

bool EnGhostA::state_1_Behavior() {
    return true;
}

bool EnGhostA::state_2_Init() {
    return true;
}

bool EnGhostA::state_2_Behavior() {
    return true;
}

bool EnGhostA::state_3_Init() {
    return true;
}

bool EnGhostA::state_3_Behavior() {
    return true;
}

bool EnGhostA::state_4_Init() {
    return true;
}

bool EnGhostA::state_4_Behavior() {
    return true;
}

bool EnGhostA::state_5_Init() {
    return true;
}

bool EnGhostA::state_5_Behavior() {
    return true;
}

bool EnGhostA::state_6_Init() {
    return true;
}

bool EnGhostA::state_6_Behavior() {
    return true;
}

bool EnGhostA::state_7_Init() {
    return true;
}

bool EnGhostA::state_7_Behavior() {
    return true;
}

bool EnGhostA::state_8_Init() {
    return true;
}

bool EnGhostA::state_8_Behavior() {
    return true;
}

bool EnGhostA::state_9_Init() {
    return true;
}

bool EnGhostA::state_9_Behavior() {
    return true;
}

bool EnGhostA::state_A_Init() {
    return true;
}

bool EnGhostA::state_A_Behavior() {
    return true;
}

bool EnGhostA::state_B_Init() {
    return true;
}

bool EnGhostA::state_B_Behavior() {
    return true;
}

void EnGhostA::EnGhostA_fn_800C8EC0() {

}

void EnGhostA::EnGhostA_fn_800C8ECC() {

}

void EnGhostA::EnGhostA_fn_800C8F28() {

}

void EnGhostA::EnGhostA_fn_800C8F54() {

}

bool EnGhostA::EnGhostA_fn_800C8F88() {
    return false;
}

bool EnGhostA::EnGhostA_fn_800C8FB8() {
    return true;
}

void EnGhostA::EnGhostA_fn_800C8FE8() {

}

void EnGhostA::EnGhostA_fn_800C902C() {

}

EnGhostA::~EnGhostA() {
    
}
