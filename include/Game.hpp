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
    void buildMap();
    void render();
    void clean();
    bool running() {return isRunning;}
    
    static const int width = 576; 
    static const int height = 768;

    static SDL_Renderer* renderer;

private:
    bool isRunning;
    SDL_Window* window;
};


#endif /* Game_hpp */