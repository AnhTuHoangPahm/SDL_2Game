#include "Timer.hpp"

Timer* Timer::clock = nullptr;

void Timer::StartCountdown(Uint32 timeMs) {
    countdownTime = timeMs;
    startTime = SDL_GetTicks();
}

Uint32 Timer::GetElapsedSeconds() {
    return (SDL_GetTicks() - startTime) / 1000; // from ms to seconds
}

Uint32 Timer::GetRemainingTime() {
    Uint32 elapsed = GetElapsedSeconds();
    return (elapsed >= countdownTime) ? 0 : (countdownTime - elapsed) / 1000; // to seconds 
}

void Timer::SetInterval(Uint32 newInterval) {
    interval = newInterval;
    lastInterval = SDL_GetTicks();
}

bool Timer::HasIntervalPassed() {
    Uint32 now = SDL_GetTicks();
    if (now - lastInterval >= interval) {
        lastInterval = now;
        return true;
    }
    return false;
}