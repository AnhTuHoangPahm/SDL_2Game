#include "TextTimer.hpp"

TextTimer::TextTimer(const std::string& fontPath, int fontSize, SDL_Color color, int x, int y, Uint32 duration)
    : textRender(Game::renderer), color(color), timerTex(nullptr), duration(duration), startTime(SDL_GetTicks())
    {

    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
    }

    timerRect.x = x;
    timerRect.y = y;
    timerRect.w = 200;
    timerRect.h = 100;
    }

TextTimer::~TextTimer()
{
    if (timerTex) SDL_DestroyTexture(timerTex);
    if (font) TTF_CloseFont(font);
}

Uint32 TextTimer::GetRemainingTime() {
    Uint32 elapsed = SDL_GetTicks() - startTime;
    return (elapsed >= duration) ? 0 : (duration - elapsed) / 1000; // to seconds 
}

void TextTimer::Update() 
{
    Uint32 remainingTime = GetRemainingTime();
    RenderText(std::to_string(remainingTime) + "s");
}

void TextTimer::RenderText(const std::string& text) {
    if (timerTex) SDL_DestroyTexture(timerTex);

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface) return;

    timerTex = SDL_CreateTextureFromSurface(textRender, surface);
    timerRect.w = surface->w;
    timerRect.h = surface->h;
    SDL_FreeSurface(surface);
}

void TextTimer::Render() {
    if (timerTex) {
        std::cerr << "text rendered";
        SDL_RenderCopy(textRender, timerTex, NULL, &timerRect);
    }
}