#pragma once
#include "Game.hpp"

class GameObject 
{
public:
    GameObject(const char* TextureSheetDir);
    virtual ~GameObject();
    virtual void Update(); // upate position, HP, damage, isAlive, etc.
    virtual void Render();

    // todo: add Collision check & handle

protected:
    // current cordination, can be overwritten
    int x_pos;
    int y_pos;

    SDL_Texture* Tex;
    SDL_Rect srcRect, destRect;

    // sprite-related
    const int FrameWidth = 64; 
    const int FrameHeight = 64;
        // animation thingy
        int FrameNum = 4; // idling stance for all objects // max = isAttack = depends
        Uint32 FrameDelay = 200; // delay per frame (default)
        int currentFrame = 0; 
        Uint32 lastFrameTime = 0; 

    //status related
    int HP;
    int Damage; 
    bool isAttack = false;
    bool isAlive = true;
};