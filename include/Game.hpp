#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>

#ifndef GAME_HPP
#define GAME_HPP 

class Game {
public:
    Game();
    ~Game();
    void Init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() {return isRunning;}

private:
    int count = 0;
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif /* Game_hpp */