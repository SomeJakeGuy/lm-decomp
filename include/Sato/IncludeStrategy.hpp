// Based on the previous decompilation effort: https://github.com/CoNesTra/zmansion/blob/main/include/Unsorted/IncludeStrategy.h

#ifndef INCLUDE_STRATEGY_HPP
#define INCLUDE_STRATEGY_HPP

#include <types.h>

#include "Sato/EnemyStrategy.hpp"

/*
.data has lbl_8035A1D8 as part of this split, maybe EnemyStrategy, IncludeStrategy and a couple others are actually a much bigger TU?
*/

class IncludeStrategy
{
    u8 mStrategyMemory[0x800];
    EnemyStrategy* mpStrategy;
    
public:
    IncludeStrategy();
    /* 0x04 */ virtual ~IncludeStrategy();

    void setStrategy(int);
    void destroyStrategy();

    void* getBuffer() { return mStrategyMemory; }
};


#endif
