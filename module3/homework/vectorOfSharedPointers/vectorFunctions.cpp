//TODO 
//function inplementation

#include<time.h>
#include <iostream>
#include <algorithm>
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
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

void add10(std::vector<std::shared_ptr<int>> vec) {
    for (const auto& it: vec) {
    *it += 10;
    }
}

void sub10(int* const ptr) {
    *ptr -= 10;
}

void sub10(std::vector<std::shared_ptr<int> > vec) {
    for (auto& it: vec) {
        sub10(it.get());
    }
}
