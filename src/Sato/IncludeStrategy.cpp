// Based on the previous decompilation effort: https://github.com/CoNesTra/zmansion/blob/main/src/Unsorted/IncludeStrategy.cpp

#include "Sato/IncludeStrategy.hpp"
#include "Sato/EnemyStrategy.hpp"

IncludeStrategy::IncludeStrategy() : mpStrategy(nullptr) {
    destroyStrategy();
}

IncludeStrategy::~IncludeStrategy() {
    destroyStrategy();
}

void IncludeStrategy::setStrategy(int entityIdx) {
    void* buffer = mStrategyMemory;
    destroyStrategy();
    EnemyStrategyInitFn* initFunc = *EnemyStrategy::getInitFunction(entityIdx);
    mpStrategy = reinterpret_cast<EnemyStrategy*>(initFunc(buffer, sizeof(mStrategyMemory)));
}

void IncludeStrategy::destroyStrategy() {
    EnemyStrategy* strategy = mpStrategy;

    if (strategy != nullptr) {
        // This object was initialized via placement new, so we
        // can just call its destructor and invalidate its pointer.
        strategy->~EnemyStrategy();
        mpStrategy = nullptr;
    }
}
