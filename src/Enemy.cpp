#include "Enemy.hpp"

Enemy::~Enemy()
{}

void Enemy::RandomMovement()
{
    static const int dx[4] = {0, 0, -1, 1};
        static const int dy[4] = {-1, 1, 0, 0};
        int dir = rand() % 4;
        int newX = x / Map::tileSize + dx[dir];
        int newY = y / Map::tileSize + dy[dir];
        
        if (newX >= 0 && newX < Game::width && newY >= 0 && newY < Game::height) {
            x = newX * Map::tileSize;
            y = newY * Map::tileSize;
        }
}

void Enemy::Update(int playerX, int playerY)
{
    // // browse the frames idle: 4 atk: 12 ...
    // if(SDL_GetTicks() - lastFrameTime > FrameDelay) {
    //     currentFrame = (currentFrame + 1); //% FrameNum;
    //     if(currentFrame > FrameNum) 
    //     {
    //         isAttack = false; //
    //         FrameDelay = 200; // set back to
    //         FrameNum = 4;     //   default 
    //         currentFrame = 0;
    //     }
    //     lastFrameTime = SDL_GetTicks();
    // }
    // //
    // playerSrc = {currentFrame * FrameWidth, 0, FrameWidth, FrameHeight};
    // playerDest = {startingX, startingY, FrameWidth, FrameHeight}; // starting position := bottom center of window (x,y,w,h). For ref:to line 13

    // // std::cout << "Current Frame: " << currentFrame << " Source Rect: "
    // //     << playerSrc.x << ", " << playerSrc.y << std::endl;

    Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastMoveTime >= 3000) {
            if (DetectPlayer(playerX, playerY)) {
                ChasePlayer(playerX, playerY);
            } else {
                RandomMovement();
            }
            lastMoveTime = currentTime;
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
    return std::abs(gridX - plGridX) <=1 && std::abs(gridY - plGridY) <=1;
}

void Enemy::ChasePlayer(int playerX, int playerY) 
{
    int gridX = x / Map::tileSize;
    int gridY = y / Map::tileSize;
    int plGridX = playerX / Map::tileSize;
    int plGridY = playerY / Map::tileSize;

    if (std::abs(plGridX - gridX) > std::abs(plGridY - gridY)) 
    {
        x += (plGridX > gridX) ? Map::tileSize : - Map::tileSize;
    } else {
        y += (plGridY > gridY) ? Map::tileSize : - Map::tileSize;
    }
}


