#ifndef TEXTTIMER_HPP
#define TEXTTIMER_HPP

#include "Game.hpp"
#include "Timer.hpp"

class TextTimer
{
public:
    TextTimer(const std::string& fontPath, int fontSize, SDL_Color color, int x, int y, Uint32 duration);
    ~TextTimer();
    // Update time from Timer
    void Update();
    Uint32 GetRemainingTime();
    // Render time text
    void RenderText(const std::string& text) ;

    // appear on screen
    void Render();

private:
    TTF_Font* font;
    SDL_Renderer* textRender;
    SDL_Texture* timerTex;
    SDL_Color color;
    SDL_Rect timerRect;
    Uint32 duration;
    Uint32 startTime;
};

#endif