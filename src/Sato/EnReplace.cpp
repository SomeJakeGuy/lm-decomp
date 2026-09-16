#include "Sato/EnReplace.hpp"
#include "Sato/EnemyStrategy.hpp"
#include "macros.h"

dummy_float_data();
enemies_float_data();

void EnReplace::doBehavior() {
    EnemyStrategyState* end = enemyStrategyStates + ARRAY_COUNT(enemyStrategyStates);
    EnemyStrategyState* current = enemyStrategyStates;
    EnemyStrategyState* found = nullptr;

    while (enemyStrategyStates != end) {
        if (enemyStrategyStates->mStateIndex == mCurrentState) {
            found = enemyStrategyStates;
        }
        current++;
    }

    if (found != nullptr)
        (this->*found->mBehaviorFunc)();
}

void EnReplace::doBehaviorInit() {
    EnemyStrategyState* end = enemyStrategyStates + ARRAY_COUNT(enemyStrategyStates);
    EnemyStrategyState* current = enemyStrategyStates;
    EnemyStrategyState* found = nullptr;

    while (enemyStrategyStates != end) {
        if (enemyStrategyStates->mStateIndex == mCurrentState) {
            found = enemyStrategyStates;
        }
        current++;
    }

    if (found != nullptr)
        (this->*found->mBehaviorInitFunc)();
}

bool EnReplace::vt_14() {
    return false;
}

bool EnReplace::state_0000_Init() { return true; }
bool EnReplace::state_0000_Behavior() { return true; }
bool EnReplace::state_0010_Init() { return true; }
bool EnReplace::state_0010_Behavior() { return true; }
bool EnReplace::state_0100_Init() { return true; }
bool EnReplace::state_0100_Behavior() { return true; }
