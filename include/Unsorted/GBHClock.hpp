#ifndef GBH_CLOCK_HPP
#define GBH_CLOCK_HPP

#include "types.h"

void resetInGameClock();
void updateInGameClock();

extern BOOL sInGameClockEnabled;
extern u64 sInGameClockTicks;
extern s32 sInGameClockHours;
extern s32 sInGameClockMinutes;
extern s32 sInGameClockSeconds;

#endif
