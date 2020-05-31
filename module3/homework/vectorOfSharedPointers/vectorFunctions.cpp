#include "vectorFunctions.hpp"
#include <algorithm>
#include <iostream>



std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec (count);
    for (auto it = 0; it < count; it++){
        vec[it] = std::make_shared<int>(it);
    }
    return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& it: vec){
        std::cout << *it << " ";
    }
    std::cout << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& it: vec){
        if(it){
            *it += 10;
        }
    }
}

void sub10(int* const ptr) {
    if(ptr){
        *ptr -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    for (auto& it: vec){
        sub10(it.get());
    }
}
