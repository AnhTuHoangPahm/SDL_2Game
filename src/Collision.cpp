#include "Collision.hpp"

bool CollisionDetect::areAdjacent(int x1, int y1, int x2, int y2) 
{
    return ((std::abs(x1 - x2) == 64 && y1 == y2) || 
            (std::abs(y1 - y2) == 64 && x1 == x2));
} 

bool CollisionDetect::areAround(int x1, int y1, int x2, int y2) 
{
    return (std::abs(x1 - x2) <= 64 
                && std::abs(y1 - y2) <= 64 
                && !(x1 == x2 && y1 == y2));
}