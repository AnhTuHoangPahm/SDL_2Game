#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
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

Player* player;

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

    player = new Player("assets/Skadi_sprite.png", renderer);


    //bgTex = TextureManager::LoadTexture("assets/VastSands.png", renderer);
    //Skadi = TextureManager::LoadTexture("assets/Skadi_sprite.png", renderer);

}

void Game::handleEvents() 
{
    //SDL_Event event;
    SDL_PollEvent(&event);
    if(SDL_QUIT == event.type) 
    {
        isRunning = false;
        // Simple input handling
        // Arrow Key 
        // case SDL_KEYDOWN:
        //     switch(event.key.keysym.sym)
        //     {
        //         case SDLK_UP:
        //             startingY -= FrameHeight;
        //             break;
        //         case SDLK_DOWN:
        //             if(startingY == height - FrameHeight) {break;}
        //             startingY += FrameHeight;
        //             break;
        //         case SDLK_LEFT:
        //             if(startingX == 0) {break;}
        //             startingX -= FrameWidth;
        //             break;
        //         case SDLK_RIGHT:
        //             if(startingX == width - FrameWidth) {break;}
        //             startingX += FrameWidth;
        //             break;
        //     }
        //     break;
        // case SDL_KEYUP:
        //     switch(event.key.keysym.sym)
        //     {
        //         case SDLK_UP:
        //             startingY -= 0;
        //             break;
        //         case SDLK_DOWN:
        //             startingY += 0;
        //             break;
        //         case SDLK_LEFT:
        //             startingX -= 0;
        //             break;
        //         case SDLK_RIGHT:
        //             startingX += 0;
        //             break;
        //     }
        //     break;
        // // Mouse click (just to test)
        // case SDL_MOUSEBUTTONUP:
        //     if(event.button.button = SDL_BUTTON_LEFT)
        //     {
        //         isAttack = true;
        //         FrameDelay = 75;
        //         FrameNum = 17;
        //         break;   
        //     }
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

}

void Game::render()
{
    SDL_RenderClear(renderer);
    //add stuff to render here
    //SDL_RenderCopy(renderer, bgTex, NULL,NULL);
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

