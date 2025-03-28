#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Game.hpp"

class Enemy : public GameObject
{
public:
    Enemy(int startX, int startY)
        : x(startX * Map::tileSize ), y(startY * Map::tileSize), prevX(x), prevY(y), lastMoveTime(SDL_GetTicks()) 
    {
        enemyTex = TextureManager::LoadTexture("assets/Tile_01.png");
    }

    ~Enemy() override;
    void Update() override; 
    // void Update(int playerX, int PlayerY); don't nêed that, see Spawner::Update()
    void Render() override;
    void RandomMovement();
    bool DetectPlayer(int playerX, int playerY);
    void ChasePlayer(int playerX, int playerY);
    void Attack();

    SDL_Rect enemySrc, enemyDest;
    static SDL_Texture* enemyTex;

    int x, y;
    int prevX, prevY;
    Uint32 lastMoveTime;

};

#endif