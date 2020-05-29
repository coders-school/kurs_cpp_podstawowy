//TODO 
//function inplementation

#include<time.h>
#include <iostream>
#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec {};
    srand(time(NULL));
    for (auto it = 0; it < count; it++) {
        vec.emplace_back(std::make_shared<int>(generateRandomNumber(count)));
    }
    return vec;
}

int generateRandomNumber(int count) {
    return rand() % count;
}

void print(std::vector<std::shared_ptr<int>> vec) {
    for (const auto& it: vec) {
        std::cout << *it;
    }
}

