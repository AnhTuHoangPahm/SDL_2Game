#include "Spawner.hpp"
#include "Enemy.hpp"

EnemySpawner* EnemySpawner::spawner = nullptr;

void EnemySpawner::AddSpawner(int gridX, int gridY)
{
    spawnerPos.emplace_back(gridX, gridY);
}

// traverse available spawners, pick one to spawn an enemy
void EnemySpawner::Spawn()
{   
    if (spawnerPos.empty() || enemies.size() >= MAX_ENEMY) return;

    int index = Game::rgn.getInt(0, spawnerPos.size() -1); // random index
    enemies.emplace_back(spawnerPos[index].first, spawnerPos[index].second);
    for (const auto& pos : spawnerPos)
    {
        std::cout << "Spawner Position: (" << pos.first << ", " << pos.second << ")" << std::endl;
        std::cout << "Enemy Spawned at: (" << enemies.back().x << ", " << enemies.back().y << ")" << std::endl;
    }
}

bool EnemySpawner::isOccupied(int x, int y) const {
    for (const auto& enemy : enemies) {
        if (enemy.x == x && enemy.y == y) {
            return true;
        }
    }
    return false;
} 

void EnemySpawner::Update(int& playerX, int& playerY)
{
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastSpawnTime >= 1750) // spawn inteval
    {
        Spawn();
        lastSpawnTime = currentTime;
    }

    for (auto i = enemies.begin(); i != enemies.end();)
    {
        if (i->x < 0 || i->x >= Game::width || i->y < 0 || i->y >= Game::height) // erase out-of-bound enemies
        {
            i = enemies.erase(i); 
        } else {
            if (i->Attack(playerX, playerY)) 
            {
                playerX = -64;
                playerY = -64;
                std::cout << "Enemy attacked Player!" << std::endl;
                break;
            } else if (!i->attackOnCD && i->DetectPlayer(playerX, playerY)) {
                if (currentTime - i->lastMoveTime >= 1500)
                {
                    i->ChasePlayer(playerX, playerY);
                    i->lastMoveTime = currentTime;
                }
            } else {
                if (currentTime - i->lastMoveTime >= 1500) 
                {
                    i->RandomMovement();
                    i->lastMoveTime = currentTime;
                }
            }
            i++; // make sure all enemy is properly iterated and updated
        }
    }
}

void EnemySpawner::Render()
{
    for (auto& enemy : enemies)
    {   
        SDL_Rect enemySrc = {0, 0, 64, 64};
        SDL_Rect enemyDest = {enemy.x, enemy.y, Map::tileSize, Map::tileSize};
        // std::cout << "Enemy Position: (" << enemy.x << ", " << enemy.y << ")" << std::endl;
        SDL_RenderCopy(Game::renderer, Enemy::enemyTex, &enemySrc, &enemyDest);
    }
}

// void EnemySpawner::ScrollDown()
// {
//     for(auto& enemy : enemies)
//     {
//         enemy.y += Map::tileSize;
//     }
// }

