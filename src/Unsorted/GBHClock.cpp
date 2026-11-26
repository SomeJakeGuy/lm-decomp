#include "Unsorted/GBHClock.hpp"

u64 sGBHClockTicks;
s32 sGBHClockHours;
s32 sGBHClockMinutes;
s32 sGBHClockSeconds;

BOOL sGBHClockEnabled = TRUE;

void resetGBHClock() {
    sGBHClockTicks = 0;
    sGBHClockHours = 0;
    sGBHClockMinutes = 0;
    sGBHClockSeconds = 0;
}

void updateGBHClock() {
    if (sGBHClockEnabled) {
        sGBHClockTicks++;
    }
    
    u64 totalTicks = (sGBHClockTicks * 10) / 30;
    sGBHClockSeconds = totalTicks % 60;
    totalTicks /= 60;

    sGBHClockMinutes = totalTicks % 60;
    sGBHClockHours = totalTicks / 60;

    if (sGBHClockHours == 6) {
        sGBHClockTicks = 0;
    }
}
