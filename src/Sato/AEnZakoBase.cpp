#include "Sato/AEnZakoBase.hpp"
#include "macros.h"

dummy_float_data();
enemies_float_data();

static EnemyStrategyState enemiesStates[2] = {
    EnemyStrategyState(0, 
        (EnemyStrategyStateFn)&AEnZakoBase::state_0_Init, 
        (EnemyStrategyStateFn)&AEnZakoBase::state_0_Behavior
    ),

    EnemyStrategyState(1, 
        (EnemyStrategyStateFn)&AEnZakoBase::state_1_Init, 
        (EnemyStrategyStateFn)&AEnZakoBase::state_1_Behavior
    ),
};


// From EnemyStrategy
void AEnZakoBase::init() {

}

void AEnZakoBase::doBehavior() {

}

void AEnZakoBase::doBehaviorInit() {

}

bool AEnZakoBase::vt_14() {
    return true;
}

bool AEnZakoBase::state_0_Init() {
    return true;
}

bool AEnZakoBase::state_0_Behavior() {
    return true;
}

bool AEnZakoBase::state_1_Init() {
    return true;
}

bool AEnZakoBase::state_1_Behavior() {
    return true;
}


// From this class
void AEnZakoBase::fn_800F5CB8() {}

void AEnZakoBase::vt_08() {
    return;
}

// From Koga::CharacterEventObserver
bool AEnZakoBase::onPlayerLeftRoom(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onCollideWithPlayer(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onSprayedWithWater(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onSprayedWithFire(Koga::CharacterEvent* msg){
    return true;
}

bool AEnZakoBase::onSprayedWithIce(Koga::CharacterEvent* msg){
    return true;
}
