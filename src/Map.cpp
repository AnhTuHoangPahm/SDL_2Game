#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "Player.hpp"

// Map::Map(const char* TileSheetDir)
// {}

Map::~Map()
{}

void Map::Update()
{
    tileSrc = {0, 0, tileSize, tileSize};
    tileDest = {0, 0, tileSize, tileSize};
}

void Map::LoadEntireMap()
{
    // clone a tile texture to entire vector
    for (size_t row=0; row<ROW; row++) // cycle thru the vectors in deque
    {
        for (size_t col=0; col<COL; col++) 
        {
            Tile tile;
            tile.x = col * tileSize; 
            tile.y = row * tileSize;
            tile.id = (row % 2);
            tile.tileTex = tmpTileTex;
            Tiles[row][col] = tile;
        }
    }
}

void Map::RenderEntireMap()
{ 
    //render the deque
    for (const auto& row : Tiles) {
        for (const auto& tile : row) {
            tileDest.x = tile.x;
            tileDest.y = tile.y;
            tileSrc.x = tile.id * tileSize;
            SDL_RenderCopy(Game::renderer, tmpTileTex, &tileSrc, &tileDest);
        }
    }
}

// void Map::UpdateCamera(SDL_Rect &camera, int startingY, int windowHeight, float scrollSpd) // startingY is actually updated => actualY
// {
//     if(startingY <= camera.h / 2) 
//     {
//         // keep player in the Y_center
//         int targetY = startingY  - camera.h / 2; // if player exceed 1/2 screen
//
//         // keep camera in-bound (Y)
//         /*  width/height - camera.w/.h == 0 (fact)
//             if targetY < 0 (be it the min) then targetY's set to 0
//             else keep targetY the same value as long as its value does not drop below 0     */
//         targetY = std::max(0, std::min(targetY, windowHeight - camera.h));
//
//         // Smooth Y_scrolling
//         camera.y += (targetY - camera.y) * scrollSpd;
//         std::cout << "Camera.y: " << Map::camera.y << std::endl; // why it's always 0??
//
//         wwhen camera reach new row
//         if (camera.y % tileSize == 0) 
//         { 
//             ScrollMap();
//         }
//     }
// }

void Map::ScrollMap()
{
    if (Player::startingY <= (Game::height / 2) )
    {
        Player::startingY += tileSize;

        std::vector<Tile> tmpRow = Tiles.back();
        Tiles.pop_back();

        // update tiles' position after deletion
        for(auto& row : Tiles) 
        {
            for(auto& tile : row) 
            {
                tile.y += tileSize;
            }
        }

        for(auto& tile : tmpRow) // update y_pos for first row that once be last row
        {
            tile.y = Tiles.front()[0].y - tileSize;
        } 

        Tiles.push_front(tmpRow);
        
        std::cout << "Map scrolled" << std::endl;
    }
}

