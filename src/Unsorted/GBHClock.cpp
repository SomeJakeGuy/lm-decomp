#include "Unsorted/GBHClock.hpp"

u64 sInGameClockTicks;
s32 sInGameClockHours;
s32 sInGameClockMinutes;
s32 sInGameClockSeconds;

BOOL sInGameClockEnabled = TRUE;

void resetInGameClock() {
    sInGameClockTicks = 0;
    sInGameClockHours = 0;
    sInGameClockMinutes = 0;
    sInGameClockSeconds = 0;
}

void updateInGameClock() {
    if (sInGameClockEnabled) {
        sInGameClockTicks++;
    }
    
    u64 totalTicks = (sInGameClockTicks * 10) / 30;
    sInGameClockSeconds = totalTicks % 60;
    totalTicks /= 60;

    sInGameClockMinutes = totalTicks % 60;
    sInGameClockHours = totalTicks / 60;

    if (sInGameClockHours == 6) {
        sInGameClockTicks = 0;
    }
}
