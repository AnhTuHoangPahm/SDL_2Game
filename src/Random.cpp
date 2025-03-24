#include "Random.hpp"

RandomGenerator::~RandomGenerator()
{}

int RandomGenerator::getInt(int a, int b) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}