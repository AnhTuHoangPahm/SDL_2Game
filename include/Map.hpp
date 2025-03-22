#pragma once
#include <vector>
#include <deque> // DoubleEndQueue
#include "TextureManager.hpp"

struct Tile
{
    int id;
    int x;
    int y;
    SDL_Texture* tileTex;
};

class Map
{
public:
    Map(const char* TileSheetDir)
        : Tiles(ROW, std::vector<Tile>(COL)) // construct a member 12x9 Vector
    {
        tmpTileTex = TextureManager::LoadTexture(TileSheetDir);
    }; 

    ~Map();
    
    void Update();
    void LoadEntireMap();
    void RenderEntireMap();
    // void UpdateCamera(SDL_Rect &camera, int actualY, int windowHeight, float scrollSpd);
    void ScrollMap();

private:
    //
    static const int ROW = 12; // 12 x 9 dynamic array
    static const int COL = 9;  // static to use in initialization list
    //Tile tile;
    const int tileSize = 64; // 64 x 64
    // Tile tex to be cloned 
    SDL_Texture* tmpTileTex;

    // that 2D vector 
    std::deque<std::vector<Tile>> Tiles; 

    SDL_Rect tileSrc, tileDest;

};