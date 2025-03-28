#include "Game.hpp"
//sdl-event
SDL_Event event;
// texture here
// SDL_Texture *playerTex, *bgTex, *Skadi;
// Rect here
SDL_Rect srcRect, destRect;

Game::Game()
{}
Game::~Game()
{}

EnemySpawner spawner;
Player* player;
Map* mapper;

SDL_Renderer* Game::renderer;

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
            //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        isRunning = true;
    }

    player = new Player("assets/Skadi_sprite.png");
    mapper = new Map("assets/grasses.png");

    //bgTex = TextureManager::LoadTexture("assets/VastSands.png", renderer);

}

void Game::buildMap()
{
    mapper->Update();
    mapper->LoadEntireMap();
    spawner.AddSpawner(0, 0);
    spawner.AddSpawner(11, 8); 
    SDL_RenderClear(renderer);
    mapper->RenderEntireMap();
    SDL_RenderPresent(renderer);
}

void Game::handleEvents() 
{
    //SDL_Event event;
    SDL_PollEvent(&event);
    if(SDL_QUIT == event.type) 
    {
        isRunning = false;
    } else {
        player->InputHandle(event);
        // std::cout << "X: " << Player::startingX << " Y: " << Player::startingY << std::endl; 
    }  
}

void Game::update()
{
    player->Update();
    mapper->Update(); 
    mapper->ScrollMap();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to render here

    mapper->RenderEntireMap();
    player->Render();
    SDL_RenderPresent(renderer);
    
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    std::cout << "Game terminated" << std::endl;
}

