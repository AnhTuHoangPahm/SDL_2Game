#ifndef TEXTTIMER_HPP
#define TEXTTIMER_HPP
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Timer.hpp"

class TextTimer
{
public:
    TextTimer(SDL_Renderer* timeRender,const char* fontPath, TTF_Font* font, int fontSize, SDL_Color color, int x, int y)
        : textRender(timeRender), color(color), timerTex(nullptr)
    {
        font = TTF_OpenFont(fontPath, fontSize);
        if (!font) {
            SDL_Log("Failed to load font: %s", TTF_GetError());
        }

        timerRect.x = x;
        timerRect.y = y;
        timerRect.w = 100;
        timerRect.h = 50;
    }

    ~TextTimer();
    // Cập nhật văn bản từ thời gian của Timer
    void Update();

    // Render văn bản
    void RenderText(const char* text) {
        if (timerTex) SDL_DestroyTexture(timerTex);

        SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
        if (!surface) return;

        timerTex = SDL_CreateTextureFromSurface(textRender, surface);
        timerRect.w = surface->w;
        timerRect.h = surface->h;
        SDL_FreeSurface(surface);
    }

    // Hiển thị lên màn hình
    void Render() {
        if (timerTex) {
            SDL_RenderCopy(textRender, timerTex, NULL, &timerRect);
        }
    }

private:
    TTF_Font* font;
    SDL_Renderer* textRender;
    SDL_Texture* timerTex;
    SDL_Color color;
    SDL_Rect timerRect;
};

#endif