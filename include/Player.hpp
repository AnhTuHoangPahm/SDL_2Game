#ifndef PLAYER_HPP
#define PLAYER_HPP

#pragma once
#include "Game.hpp"
#include "GameObject.hpp"

class Player : public GameObject 
{
public:
    Player(const char* PlayerTextureSheetDir); //, SDL_Renderer* ren);
    ~Player() override;
    static int getX() {return startingX;} // startingX, Y are actually modified (confusion++)
    static int getY() {return startingY;}
    void Update() override;
    void Render() override;
    void InputHandle(SDL_Event event);

    static int startingX;
    static int startingY;

    SDL_Rect playerSrc, playerDest;
private:
// override name of these from parent class
    SDL_Texture* playerTex;

    int EXP;
    int Level;
};

#endif