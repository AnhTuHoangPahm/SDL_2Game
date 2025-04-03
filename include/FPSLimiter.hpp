#ifndef FPS_LIMITER_HPP
#define FPS_LIMITER_HPP

#include "Game.hpp"

class FPSLimiter
{
public:
    void Limit(int FrameDelay, int FrameTime);
};

#endif