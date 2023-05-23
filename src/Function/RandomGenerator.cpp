#include <iostream>
#include <random>
#include "../include.h"


void generatorNumber(int min, int max) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    std::cout << dis(gen) << std::endl;
    
}