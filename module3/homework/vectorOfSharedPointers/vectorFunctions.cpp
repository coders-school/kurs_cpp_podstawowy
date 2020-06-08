#include "vectorFunctions.hpp"

#include<iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    if (count < 1) {
        return{};
    }
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for (int i = 0; i < count; i++) {
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}

void print (const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        std::cout << *el << ' ';
    }
    std::cout << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (auto & el :vec) {
        if(el){
            *el += 10;
        }
    }
}

void sub10(int * const num) {
    if(num) {
        *num -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        sub10(el.get());
    }
}
