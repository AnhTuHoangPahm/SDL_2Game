#include "Player.hpp"

int Player::startingX = Game::width/2 -32;
int Player::startingY = Game::height - 64;

Player::Player(const char* PlayerTextureSheetDir) : GameObject::GameObject(PlayerTextureSheetDir)
{
    playerTex = TextureManager::LoadTexture("assets/Skadi_sprite.png");
}

Player::~Player()
{}

void Player::Render() 
{
    SDL_RenderCopy(Game::renderer, playerTex, &playerSrc, &playerDest);    
}

void Player::Update()
{
    // browse the frames idle: 4 atk: 12 ...
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
    playerSrc = {currentFrame * FrameWidth, 0, FrameWidth, FrameHeight};
    playerDest = {startingX, startingY, FrameWidth, FrameHeight}; // starting position := bottom center of window (x,y,w,h). For ref:to line 13

    // std::cout << "Current Frame: " << currentFrame << " Source Rect: "
    //     << playerSrc.x << ", " << playerSrc.y << std::endl;
}

void Player::InputHandle(SDL_Event event)
{
    // Simple input handling
    // Arrow Key 
    if(SDL_KEYDOWN == event.type) 
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                startingY -= FrameHeight;
                break;
            case SDLK_DOWN:
                if(startingY == Game::height - FrameHeight) {break;}
                startingY += FrameHeight;
                break;
            case SDLK_LEFT:
                if(startingX == 0) {break;}
                startingX -= FrameWidth;
                break;
            case SDLK_RIGHT:
                if(startingX == Game::width - FrameWidth) {break;}
                startingX += FrameWidth;
                break;
        }
    }

    if(SDL_KEYUP == event.type)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
                startingY -= 0;
                break;
            case SDLK_DOWN:
                playerDest.y += 0;
                break;
            case SDLK_LEFT:
                startingX -= 0;
                break;
            case SDLK_RIGHT:
                startingX += 0;
                break;
        }
    }
    // Mouse click (just to test)
    if (SDL_MOUSEBUTTONUP == event.type)
    {
        if(event.button.button = SDL_BUTTON_LEFT)
        {
            isAttack = true;
            FrameDelay = 45;
            FrameNum = 17; 
        }
    }
}