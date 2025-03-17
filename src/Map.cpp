#include "TextureManager.hpp"
#include "Map.hpp"

// Map::Map(const char* TileSheetDir) 
// {}

Map::~Map()
{}

// void Map::Load1Tile(const char* TileSheetDir)
// {
//     tmpTileTex = TextureManager::LoadTexture(TileSheetDir);
// }

void Map::Update()
{
    tileSrc = {0, 0, tileSize, tileSize};
    tileDest = {0, 0, tileSize, tileSize};
}

void Map::RenderEntireMap()
{   
    // clone a tile texture to entire vector
    for (size_t row=0; row<ROW; row++) // tiles_p_rơw = vec.size() / cycle thru the arrays in vector
    {
        for (size_t col=0; col<COL; col++) //
        {
            Tile tile;
            tile.x = col * tileSize;
            tile.y = row * tileSize;
            tile.tileTex = tmpTileTex; // refer to Render1Tile()
            Tiles[row][col] = tile;
        }
    }
    //render them
    for (const auto& row : Tiles) {
        for (const auto& tile : row) {
            tileDest.x = tile.x;
            tileDest.y = tile.y;
            SDL_RenderCopy(Game::renderer, tile.tileTex, &tileSrc, &tileDest);
        }
    }
}

// void Map::RenderEntireMap(Tile TileArray[12][9])
// {
//     for (int i = 0; i < 12; i++)
//     {
//         for (int j = 0; j < 9; j++) 
//         {
//             TileArray[i][j].tileTex = TextureManager::LoadTexture("assets/Tile_01.png");
//             SDL_RenderCopy(Game::renderer, TileArray[i][j].tileTex, &tileSrc, &tileDest);
//             tileDest.x += 64;
//         }
//         tileDest.x = 0;
//         tileDest.y += 64;
//     }
// }


