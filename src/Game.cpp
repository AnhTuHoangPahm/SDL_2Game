#include "Game.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Spawner.hpp"
#include "Timer.hpp"
#include "TextTimer.hpp"

//sdl-event
SDL_Event event;
// Rect here
SDL_Rect srcRect, destRect;

Game::Game()
{}
Game::~Game()
{}

Player* player;
Map* mapper;

SDL_Renderer* Game::renderer;
RandomGenerator Game::rgn;

void Game::Init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen) 
{
    // set Uint32 flag -> fullscreen? -> SDL_WINDOW_FULLSCREEN.
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
            //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        isRunning = true;
    }

    player = new Player("assets/Skadi_sprite.png");
    mapper = new Map("assets/grasses.png");

    //bgTex = TextureManager::LoadTexture("assets/VastSands.png", renderer);

    TTF_Init();
}

SDL_Color red = {255, 0, 0, 255};
TextTimer* timer = new TextTimer("ttfont/DePixelHalbfett.ttf", 22, red, 200, 200, 150000);

void Game::buildMap()
{   
    mapper->Update();
    mapper->LoadEntireMap();

    if (EnemySpawner::spawner == nullptr) {
        EnemySpawner::spawner = new EnemySpawner();
    }

    EnemySpawner::spawner->AddSpawner(0, 0);
    EnemySpawner::spawner->AddSpawner(0, 8);
    EnemySpawner::spawner->AddSpawner(9, 0);
    EnemySpawner::spawner->AddSpawner(9, 8); 
    EnemySpawner::spawner->AddSpawner(5, 5);

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
    timer->Update();
    player->Update();
    EnemySpawner::spawner->Update(Player::startingX, Player::startingY);
    mapper->Update(); 
    // mapper->ScrollMap();

    // if(mapper->ScrollMap())
    // {
    //     spawner.ScrollDown();
    // }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to render here

    mapper->RenderEntireMap();
    player->Render();
    EnemySpawner::spawner->Render();

    timer->Render(); 
    SDL_RenderPresent(renderer);
    
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    std::cout << "Game terminated" << std::endl;
}