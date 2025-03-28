#ifndef RANDOM_HPP
#define RANDOM_HPP
#include <random>

class RandomGenerator {
public:
                         // ?  v
    RandomGenerator() : gen(rd( )) {} // result_type operator ()
    ~RandomGenerator();
    // radomize integer in [a, b]
    int getInt(int a, int b);
    
private:
    std::random_device rd;   // Random entropy source
    std::mt19937 gen;        // Random Number generator Mersenne Twister
};

#endif
