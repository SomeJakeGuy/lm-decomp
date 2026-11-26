#ifndef GBH_CLOCK_HPP
#define GBH_CLOCK_HPP

#include "types.h"

void resetGBHClock();
void updateGBHClock();

extern BOOL sGBHClockEnabled;
extern u64 sGBHClockTicks;
extern s32 sGBHClockHours;
extern s32 sGBHClockMinutes;
extern s32 sGBHClockSeconds;

#endif
