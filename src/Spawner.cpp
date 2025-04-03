#include "Spawner.hpp"

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

void EnemySpawner::Update(int& playerX, int& playerY)
{
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime - lastSpawnTime >= 3000) // spawn inteval
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
            if (currentTime - i->lastMoveTime >= 1800) //  move interval
            {   
                if (i->DetectPlayer(playerX, playerY)) {
                    i->ChasePlayer(playerX, playerY);
                    if (i->Attack(playerX, playerY)) {
                        playerX = -64;
                        playerY = -64;
                        std::cout << "Enemy Attacked Player!" << std::endl;
                        break;
                    }
                } else {
                    i->RandomMovement();
                    std::cout << "Time since last move: " << (currentTime - i->lastMoveTime) << " ms" << std::endl;
                }
                i->lastMoveTime = currentTime;
            }
            i++; // make sure all enemy is properly iterated and updated
        }
    }
}

void EnemySpawner::Render()
{
    for (auto& enemy : enemies)
    {   
        // enemy.FrameNum = 8;
        // // browse the frames idle: 4 atk: 12 ...
        // if(SDL_GetTicks() - enemy.lastFrameTime > enemy.FrameDelay) {
        //     enemy.currentFrame = (enemy.currentFrame + 1); //% FrameNum;
        //     if(enemy.currentFrame > enemy.FrameNum) enemy.currentFrame = 0;
        //     enemy.lastFrameTime = SDL_GetTicks();
        // }
    // 
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

