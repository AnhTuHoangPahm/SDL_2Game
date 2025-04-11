#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Random.hpp"
#include "Map.hpp"
#include "Collision.hpp"

class Map;
class EnemySpawner;

class Enemy : public GameObject
{
public:
    Enemy(int startX, int startY);
    ~Enemy() override;
    // void Update(int playerX, int PlayerY); don't need that, see Spawner::Update()
    void RandomMovement();
    bool DetectPlayer(int playerX, int playerY);
    void ChasePlayer(int playerX, int playerY);
    bool Attack(int playerX, int playerY);

    SDL_Rect enemySrc, enemyDest;
    static SDL_Texture* enemyTex;

    int x, y;
    int prevX, prevY;
    Uint32 lastMoveTime;
    // Uint32 lastAttackTime;
    Uint32 attackStartTime = 0;

    bool attackOnCD = false;
    

};

#endif