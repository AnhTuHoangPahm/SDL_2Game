#pragma once
#include "GameObject.hpp"

class Player : public GameObject 
{
public:
    Player(const char* PlayerTextureSheetDir); //, SDL_Renderer* ren);
    ~Player() override;
    void Update() override;
    void Render() override;
    void InputHandle(SDL_Event event);
    
private:
// override name of these from parent class
    SDL_Texture* playerTex;
    SDL_Rect playerSrc, playerDest;

//
    int startingX = 576/2 -32;
    int startingY = 784 - 64;
//

    int EXP;
    int Level;
};