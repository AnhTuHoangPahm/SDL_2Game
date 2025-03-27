#ifndef MAP_HPP
#define MAP_HPP

#pragma once
#include <vector>
#include <deque> // DoubleEndQueue
#include "TextureManager.hpp"

struct Tile
{
    
    int id = 0;
    int x = 0;
    int y = 0;
    bool hasEnemy = false;
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
    //
    static const int ROW = 12; // 12 x 9 dynamic array
    static const int COL = 9;  // static to use in initialization list
    //Tile tile;
    static const int tileSize = 64; // 64 x 64

private:
    // Tile tex to be cloned 
    SDL_Texture* tmpTileTex;
        SDL_Texture* enemytile = TextureManager::LoadTexture("assets/Tile_01.png"); // add tex from enemy class instead.

    // that 2D vector 
    std::deque<std::vector<Tile>> Tiles; 

    SDL_Rect tileSrc, tileDest;

};

#endif