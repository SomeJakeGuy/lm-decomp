#include "Unsorted/8002B4B8.hpp"
#include "Unsorted/GBHClock.hpp"

s32 checkTimeRange(s32 lower, s32 upper) {
    s32 currentTimeInSeconds = sGBHClockMinutes + sGBHClockHours * 60;

    if (currentTimeInSeconds >= lower && currentTimeInSeconds < upper) {
        return 1;
    }
    
    if (currentTimeInSeconds >= upper) {
        return 2;
    }

    return 0;
}
