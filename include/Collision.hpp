#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <cmath>

class CollisionDetect
{
    public:
    static bool areAdjacent(int x1, int y1, int x2, int y2) {
      return ((std::abs(x1 - x2) == 64 && y1 == y2) || (std::abs(y1 - y2) == 64 && x1 == x2));
    }
};

#endif