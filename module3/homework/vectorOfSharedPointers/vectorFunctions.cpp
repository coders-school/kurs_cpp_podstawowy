//TODO 
//function inplementation

#include<time.h>
#include <iostream>
#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec {};
    for (auto it = 0; it < count; it++) {
        vec.emplace_back(std::make_shared<int>(generateRandomNumber(count)));
    }
    return vec;
}

int generateRandomNumber(int count) {
    srand(time(NULL));
    return rand() % count;
}

