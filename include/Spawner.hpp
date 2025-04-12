#ifndef SPAWNER_HPP
#define SPAWNER_HPP 

#include "Game.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
// #include "Enemy.hpp"
#include "Collision.hpp"

class Enemy;

class EnemySpawner
{
public:
    EnemySpawner() : lastSpawnTime(SDL_GetTicks())
    {}
    void AddSpawner(int gridX, int gridY);
    void Spawn();
    void Render();
    bool isOccupied(int x, int y) const;
    void Update(int& playerX, int& playerY); 
    // void ScrollDown(); // no usage
    
    std::vector<std::pair<int, int>> spawnerPos;
    std::vector<Enemy> enemies; // store each enemy
    Uint32 lastSpawnTime;

    static EnemySpawner* spawner;
private:
    const int MAX_ENEMY = 13;
};

#endif 