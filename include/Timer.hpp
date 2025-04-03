#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

class Timer {
public:
    Timer() : startTime(0), countdownTime(0), lastInterval(0), interval(1000) {}

    // countdown at pre-defined time(ms)
    void StartCountdown(Uint32 timeMs);

    // get time passed
    Uint32 GetElapsedSeconds();

    // Countdown time left (ms)
    Uint32 GetRemainingTime();

    // set duration of each interval
    void SetInterval(Uint32 newInterval);

    // check if an interval is completed
    bool HasIntervalPassed();
    
private:
    Uint32 startTime;       // start to countdown from this time (ms)
    Uint32 countdownTime;   // countdown time (ms)
    Uint32 lastInterval;    // last checked interval time (ms)
    Uint32 interval;        // interval duration (ms)
};

#endif // TIMER_H
