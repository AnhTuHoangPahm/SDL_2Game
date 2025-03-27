#include "TextTimer.hpp"

TextTimer::~TextTimer()
{
    if (timerTex) SDL_DestroyTexture(timerTex);
    if (font) TTF_CloseFont(font);
}

void TextTimer::Update() 
{
    
}
    
