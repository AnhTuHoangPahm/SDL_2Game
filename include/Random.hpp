#ifndef RANDOM_HPP
#define RANDOM_HPP
#include <random>

class RandomGenerator {
public:
    
    RandomGenerator() : gen(rd()) {}
    ~RandomGenerator();
    // radomize integer in [a, b]
    int getInt(int a, int b);
    
private:
    std::random_device rd;   // Random entropy source
    std::mt19937 gen;        // Bộ sinh số giả ngẫu nhiên Mersenne Twister

};

#endif
