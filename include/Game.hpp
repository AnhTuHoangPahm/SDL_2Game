#ifndef GAME_HPP
#define GAME_HPP 

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <string>
#include <vector>
#include <deque> // DoubleEndQueue
#include <ctime>
#include <cmath>
#include <cstdlib>

#include "FPSLimiter.hpp"
#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Random.hpp"
#include "Map.hpp"
#include "Enemy.hpp"
#include "Spawner.hpp"
#include "Player.hpp"

class Game {
public:
    Game();
    ~Game();
    void Init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);
    void handleEvents();   
    void update();
    void buildMap();
    void render();
    void clean();
    bool running() {return isRunning;}
    
    static const int width = 576; 
    static const int height = 768;

    static SDL_Renderer* renderer;
    static RandomGenerator rgn;

private:
    bool isRunning;
    SDL_Window* window;
};


#endif /* Game_hpp */