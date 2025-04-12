#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* TextureSheetDir)
{
    Tex = TextureManager::LoadTexture(TextureSheetDir);
}

GameObject::~GameObject()
{}

void GameObject::Update()
{
    srcRect = {0, 0, 64, 64};
    destRect = {0, 0, 64, 64};
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, Tex, &srcRect, &destRect);
}