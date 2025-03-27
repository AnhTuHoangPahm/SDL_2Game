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
    Uint32 startTime;       // Thời điểm bắt đầu đếm
    Uint32 countdownTime;   // Thời gian đếm ngược (ms)
    Uint32 lastInterval;    // Thời điểm kiểm tra interval cuối cùng
    Uint32 interval;        // Khoảng thời gian cần trôi qua (ms)
};

#endif // TIMER_H
