#include "Enemy.hpp"

SDL_Texture* Enemy::enemyTex = TextureManager::LoadTexture("assets/Tile_01.png");

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

    if (validMoves.empty()) // allow going back if no more available move
    {
        validMoves.push_back((prevX / Map::tileSize == x / Map::tileSize && prevY / Map::tileSize == y / Map::tileSize) ? 0 : 1);
    }

    // move randomly based on valid directions
    if (!validMoves.empty())
    {
        int dir = validMoves[Game::rgn.getInt(0, validMoves.size() - 1)];
            std::cout << "Valid Moves: " << validMoves.size() << std::endl;
            std::cout << "Random Move: " << dir << std::endl;
            
        prevX = x;
        prevY = y;

        x += dx[dir] * Map::tileSize; 
        y += dy[dir] * Map::tileSize;
    }
    
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

bool Enemy::Attack(int playerX, int playerY) {
    Uint32 currentTime = SDL_GetTicks();
    if (CollisionDetect::areAdjacent(x, y, playerX, playerY)) {
        if (currentTime - lastAttackTime >= 1000) {
            lastAttackTime = currentTime;
            return true;
        }
    }
    return false;
}

