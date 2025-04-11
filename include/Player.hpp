#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
// #include "Enemy.hpp"
// #include "Spawner.hpp"

class Enemy;
class EnemySpawner;

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
    void AttackEnemy(std::vector<Enemy>& enemies, int playerX, int playerY, int dirX, int dirY);

    static int startingX;
    static int startingY;

    static int targetX;
    static int targetY;
    
    SDL_Rect playerSrc, playerDest;
private:
// override name of these from parent class
    SDL_Texture* playerTex;

    int EXP;
    int Level;
};

#endif