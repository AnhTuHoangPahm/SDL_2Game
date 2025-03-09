#include "Game.hpp"
const int width = 1024;
const int height = 600;
Game *game = nullptr;

int main(int argc, char* argv[]) {
    game = new Game();
    game->Init("Alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);
    while(game->running()) {

        game->handleEvents();
        game->update();
        game->render();

    }

    game->clean();
    return 0;
}
