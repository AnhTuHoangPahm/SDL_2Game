#include "Spawner.hpp"

void EnemySpawner::AddSpawner(int gridX, int gridY)
{
    spawnerPos.emplace_back(gridX, gridY);
}
// traverse available spawners, pick one to spawn an enemy
void EnemySpawner::Spawn()
{   
    if (spawnerPos.empty() || enemies.size() >= MAX_ENEMY) return;
    int index = Game::rgn.getInt(0, 100) % spawnerPos.size();
    enemies.emplace_back(spawnerPos[index].first, spawnerPos[index].second);
}

void EnemySpawner::Update(int playerX, int playerY)
{
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastSpawnTime >= 2000) // 2 seconds inteval
    {
        Spawn();
        lastSpawnTime = currentTime;
    }

    for (auto i = enemies.begin(); i != enemies.end();)
    {
        if (i->x < 0 || i->x >= Game::width || i->y < 0 || i->y >= Game::height) // erase out-of-bound enemies as map scrolls
        {
            i = enemies.erase(i); 
        } else {
            if (currentTime - i->lastMoveTime >=3000) // 3s move interval
            {
                if (i->DetectPlayer(playerX, playerY))
                {
                    i->ChasePlayer(playerX, playerY);
                } else {
                    i->RandomMovement();
                }
                i->lastMoveTime = currentTime;
            }
            i++; // make sure all enemy is properly iterated and updated
        }
    }
}

void EnemySpawner::ScrollDown()
{
    for(auto& enemy : enemies)
    {
        enemy.y += Map::tileSize;
    }
}

