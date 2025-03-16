#include "GameObject.hpp"
#include "TextureManager.hpp" // load objTex


GameObject::GameObject(const char* TextureSheetDir, SDL_Renderer* ren)
{
    renderer = ren;
    Tex = TextureManager::LoadTexture(TextureSheetDir, ren);
}

GameObject::~GameObject()
{}

void GameObject::Update()
{
    x_pos = 0;
    y_pos = 0;
        // x  y  h   w
    srcRect = {0, 0, 64, 64};
    destRect = {x_pos, y_pos, 64, 64};
}

void GameObject::Render()
{
    SDL_RenderCopy(renderer, Tex, &srcRect, &destRect);
}


