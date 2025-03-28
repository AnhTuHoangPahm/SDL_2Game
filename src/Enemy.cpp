#include "Enemy.hpp"

Enemy::~Enemy()
{}

void Enemy::RandomMovement()
{
    static const int dx[4] = {0, 0, -1, 1};
    static const int dy[4] = {-1, 1, 0, 0};
    
    std::vector<int> validMoves;
    // push valid directions into validMoves
    for (int i=0; i<4; i++)
    {
        int newX = x / Map::tileSize + dx[i];
        int newY = y / Map::tileSize + dy[i];

        if (newX >= 0 && newX < Map::COL && newY>0 && newY < Map::ROW) // inside the map
        {
            if (!(newX == prevX / Map::tileSize && newY == prevY / Map::tileSize)) // not going back to prev tile
            {
                validMoves.push_back(i);
            }
        }
    }

    // move randomly based on valid directions
    if (!validMoves.empty())
    {
        int dir = validMoves[Game::rgn.getInt(0,30) % 4];
        prevX = x;
        prevY = y;
        x += dx[dir] * Map::tileSize;
        y += dx[dir] * Map::tileSize;
    }
    
}

void Enemy::Render()
{
    SDL_RenderCopy(Game::renderer, enemyTex, &enemySrc, &enemyDest);
}

bool Enemy::DetectPlayer(int playerX, int playerY) 
{
    int gridX = x / Map::tileSize;
    int gridY = y / Map::tileSize;
    int plGridX = playerX / Map::tileSize;
    int plGridY = playerY / Map::tileSize;
    // detect range: 1 tile
    return std::abs(gridX - plGridX) <=1 && std::abs(gridY - plGridY) <=1; 
}

void Enemy::ChasePlayer(int playerX, int playerY) 
{
    int gridX = x / Map::tileSize;
    int gridY = y / Map::tileSize;
    int plGridX = playerX / Map::tileSize;
    int plGridY = playerY / Map::tileSize;

    prevX = x;
    prevY = y;

    if (std::abs(plGridX - gridX) > std::abs(plGridY - gridY)) // dx > dy, as when player moves right or left 
    {
        x += (plGridX > gridX) ? Map::tileSize : - Map::tileSize;
    } else { // player move up or down
        y += (plGridY > gridY) ? Map::tileSize : - Map::tileSize;
    }
}

