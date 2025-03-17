#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Map.hpp"
//sdl-event
SDL_Event event;
// window config
const int width = 576; 
const int height = 784;
// texture* here
SDL_Texture *playerTex, *bgTex, *Skadi;
// Rect here
SDL_Rect srcRect, destRect;
// (Player) char_skadi (todo: throw in GameObject, not here)
    // bool isAttack = false;
    // SDL_Rect SkadiSrc, SkadiDest;
    // int startingX = 576/2 - 32; 
    // int startingY = 784 - 64;
    // // more things declared here
    // // animation thingy 
    // int FrameNum = 4; // idling stance; atk= max= 17
    // int FrameWidth = 64, FrameHeight = 64;
    // Uint32 FrameDelay = 200; // Milliseconds per frame
    // int currentFrame = 0; // for anim
    // Uint32 lastFrameTime = 0; // for anim

Game::Game()
{}
Game::~Game()
{}

Player* player;

Map* mapper;
// std::vector<std::vector<Tile>> Tiles(TILES_P_COL, std::vector<Tile>(TILES_P_ROW));

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
    mapper = new Map("assets/Tile_01.png");

    //bgTex = TextureManager::LoadTexture("assets/VastSands.png", renderer);

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
    }  
}

void Game::update()
{
/*    // browse the frames idle: 4 atk: 12 ...
    if(SDL_GetTicks() - lastFrameTime > FrameDelay) {
        currentFrame = (currentFrame + 1); //% FrameNum;
        if(currentFrame > FrameNum) 
        {
            isAttack = false; //
            FrameDelay = 200; // set back to
            FrameNum = 4;     //   default 
            currentFrame = 0;
        }
        lastFrameTime = SDL_GetTicks();
    }
    // 

    SkadiSrc = {currentFrame * FrameWidth, 0, FrameWidth, FrameHeight};
    SkadiDest = {startingX, startingY, FrameWidth, FrameHeight}; // starting position := bottom center of window (x,y,w,h)   
    
    *//*(code.old)*/

    player->Update();
    mapper->Update();

}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to render here
    //SDL_RenderCopy(renderer, bgTex, NULL,NULL);
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

