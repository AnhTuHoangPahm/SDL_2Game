#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texturefile, SDL_Renderer* ren)
{
    SDL_Surface* tmpSurface = IMG_Load(texturefile);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}