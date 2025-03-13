#include "FPSLimiter.hpp"

void FPSLimiter::Limit(int FrameDelay, int FrameTime)
{
    if(FrameDelay > FrameTime) 
    {
        SDL_Delay(FrameDelay - FrameTime);
    }
}
