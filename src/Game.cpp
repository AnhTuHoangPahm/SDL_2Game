#include "Game.hpp"
#include "TextureManager.hpp"

SDL_Texture *playerTex, *bgTex;
SDL_Rect srcRect, destRect;

Game::Game()
{}
Game::~Game()
{}

void Game::Init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen) 
{
    // set Uint32 flag -> fullscreen?
    int flag = 0;
    if (fullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    // initialise and check sdl status
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) 
    {
        // create a window, renderer 
        window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flag);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        // check renderer's status
        if(renderer)
        {
            // give renderer some work
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        isRunning = true;
    }
    
    // 1.Load pixels -> 2.Make it a Texture
    playerTex = TextureManager::LoadTexture("assets/Knight.png", renderer);
    //load background
    bgTex = TextureManager::LoadTexture("assets/VastSands.png", renderer);
}

void Game::handleEvents() 
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) 
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    count++;
    destRect ={100, 350, 100, 100};
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to render here
    SDL_RenderCopy(renderer, bgTex, NULL,NULL);
    SDL_RenderCopy(renderer, playerTex, NULL, &destRect);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game terminated" << std::endl;
}

