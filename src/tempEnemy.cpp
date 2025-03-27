#include "Game.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

const int TILE_SIZE = 64;
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

class Enemy {
public:
    int x, y;
    Uint32 lastMoveTime;

    Enemy(int startX, int startY) : x(startX * TILE_SIZE), y(startY * TILE_SIZE), lastMoveTime(SDL_GetTicks()) {}

    void moveRandomly() {
        static const int dx[4] = {0, 0, -1, 1};
        static const int dy[4] = {-1, 1, 0, 0};
        int dir = rand() % 4;
        int newX = x / TILE_SIZE + dx[dir];
        int newY = y / TILE_SIZE + dy[dir];
        
        if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT) {
            x = newX * TILE_SIZE;
            y = newY * TILE_SIZE;
        }
    }

    bool detectPlayer(int playerX, int playerY) const {
        int gridX = x / TILE_SIZE;
        int gridY = y / TILE_SIZE;
        int pGridX = playerX / TILE_SIZE;
        int pGridY = playerY / TILE_SIZE;
        return std::abs(gridX - pGridX) <= 1 && std::abs(gridY - pGridY) <= 1;
    }

    void chasePlayer(int playerX, int playerY) {
        int gridX = x / TILE_SIZE;
        int gridY = y / TILE_SIZE;
        int pGridX = playerX / TILE_SIZE;
        int pGridY = playerY / TILE_SIZE;
        
        if (std::abs(pGridX - gridX) > std::abs(pGridY - gridY)) {
            x += (pGridX > gridX) ? TILE_SIZE : -TILE_SIZE;
        } else {
            y += (pGridY > gridY) ? TILE_SIZE : -TILE_SIZE;
        }
    }

    void update(int playerX, int playerY) {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastMoveTime >= 3000) {
            if (detectPlayer(playerX, playerY)) {
                chasePlayer(playerX, playerY);
            } else {
                moveRandomly();
            }
            lastMoveTime = currentTime;
        }
    }
};