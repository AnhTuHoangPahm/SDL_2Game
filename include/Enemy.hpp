#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Game.hpp"
#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Random.hpp"
#include "Map.hpp"
#include "Player.hpp"

class Enemy : public GameObject
{
public:
    Enemy(const char* EnemyTextureSheetDir, int startX, int startY)
        : x(startX * Map::tileSize ), y(startY * Map::tileSize), lastMoveTime(SDL_GetTicks()) 
    {
        enemyTex = TextureManager::LoadTexture("assets/.png");
    }

    ~Enemy() override;
    void Update() override;
    void Update(int playerX, int PlayerY);
    void Render() override;
    void RandomMovement();
    bool DetectPlayer(int playerX, int playerY);
    void ChasePlayer(int playerX, int playerY);
    void Attack();

    SDL_Rect enemySrc, enemyDest;

private:
    int x, y;
    SDL_Texture* enemyTex;
    Uint32 lastMoveTime;

};

#endif