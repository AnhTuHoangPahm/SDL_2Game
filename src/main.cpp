#include "Game.hpp"

//input w, h * 5/4 == actual w, h
// //window config
// const int width = 576; // actual window 720 x 980 
// const int height = 768; //

// for fps limiter
const int FPS = 60;
const int FrameDelay = 1000 / FPS;

FPSLimiter Limiter;

int main(int argc, char* argv[]) {
    int a = TTF_Init();
    if(a==-1) std::cerr << TTF_GetError() << "\n";
    else std::cerr << "TTF inited\n";
    Game* game = nullptr;

    game = new Game();

    game->Init("A Window", SDL_WINDOWPOS_CENTERED, 30, Game::width, Game::height, false);

    game->buildMap();
    
    while(game->running()) {

        Uint32 FrameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();

        int FrameTime = SDL_GetTicks() - FrameStart;
        Limiter.Limit(FrameDelay, FrameTime);
        
    }

    game->clean();
    return 0;
}
