#ifndef GAME_HPP
#define GAME_HPP 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>

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

    static SDL_Renderer* renderer;

private:
    bool isRunning;
    SDL_Window* window;
};


#endif /* Game_hpp */