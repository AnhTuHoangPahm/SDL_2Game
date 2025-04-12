#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <cmath>

class CollisionDetect
{
public:
    // 4 tiles around
    static bool areAdjacent(int x1, int y1, int x2, int y2);

    // 8 tiles around
    static bool areAround(int x1, int y1, int x2, int y2);

};

#endif