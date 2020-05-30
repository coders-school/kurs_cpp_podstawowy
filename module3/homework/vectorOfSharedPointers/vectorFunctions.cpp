#include <iostream>
#include <algorithm>
#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec (count);
    for (auto it = 0; it < count; it++) {
        vec[it] = std::make_shared<int>(it);
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>> vec) {
    for (const auto& it: vec) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

void add10(std::vector<std::shared_ptr<int>> vec) {
    for (const auto& it: vec) {
        if(it != nullptr){
            *it += 10;
        }
    }
}

void sub10(int* const ptr) {
    if(ptr != nullptr){
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int> > vec) {
    for (auto& it: vec) {
        sub10(it.get());
    }
}
