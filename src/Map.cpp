#include "Map.hpp"

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


// bool Map::ScrollMap()
// {
//     if (Player::startingY <= (Game::height / 2) - tileSize )
//     {
//         Player::startingY += tileSize;

//         std::vector<Tile> newRow; 
//         int newId = Tiles.back()[0].id;
//         int newY = Tiles.back()[0].y - (ROW-1) * tileSize; // = 0;

//         Tiles.pop_back();

//         // update tiles' position after deletion
//         for(auto& row : Tiles) 
//         {
//             for(auto& tile : row) 
//             {
//                 tile.y += tileSize; // shift down
//             }
//         }

//         for (size_t col=0; col<COL; col++) 
//         {
//             Tile tile;
//             tile.x = col * tileSize; 
//             tile.y = newY;
//             tile.id = newId;
//             tile.tileTex = tmpTileTex;
//             // if (Game::rgn.getInt(0, 100) % 100 < 10) 
//             // {
//             //     tile.hasEnemy = true;
//             // }
//             newRow.push_back(tile);
//         }

//         Tiles.push_front(newRow);
        
//         std::cout << "Map scrolled" << std::endl;
//         return true;
//     } else {
//         return false;
//     }
// }