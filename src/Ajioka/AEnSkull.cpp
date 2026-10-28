#include "Ajioka/AEnSkull.hpp"
#include "macros.h"

dummy_float_data()
enemies_float_data()


static EnemyStrategyState enemiesStates[1] = {
    {
        0, 
        (EnemyStrategyStateFn)&AEnSkull::state_0_Init, 
        (EnemyStrategyStateFn)&AEnSkull::state_0_Behavior
    },
};

AEnSkull::AEnSkull() {
    
}

void AEnSkull::doBehavior() {

}

void AEnSkull::doBehaviorInit() {

}

bool AEnSkull::EnGhostA_fn_800C8F88() {
    return true;
}

bool AEnSkull::state_0_Init() {
    return false;
}

bool AEnSkull::state_0_Behavior() {
    return true;
}

AEnSkull::~AEnSkull() {
    
}
