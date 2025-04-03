#ifndef SPAWNER_HPP
#define SPAWNER_HPP 

#include "Game.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Enemy.hpp"
#include "Collision.hpp"

class EnemySpawner
{
public:
    EnemySpawner() : lastSpawnTime(SDL_GetTicks())
    {}
    void AddSpawner(int gridX, int gridY);
    void Spawn();
    void Render();
    void Update(int& playerX, int& playerY); 
    void ScrollDown();
    
    std::vector<std::pair<int, int>> spawnerPos; // pair as pos = (x, y)
    std::vector<Enemy> enemies; // store each enemy
    Uint32 lastSpawnTime;
private:
    const int MAX_ENEMY = 13;
};

#endif 