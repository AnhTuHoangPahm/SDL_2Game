#include "GameObject.hpp"
#include "TextureManager.hpp" // load objTex


GameObject::GameObject(const char* TextureSheetDir)
{
    Tex = TextureManager::LoadTexture(TextureSheetDir);
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
    SDL_RenderCopy(Game::renderer, Tex, &srcRect, &destRect);
}


