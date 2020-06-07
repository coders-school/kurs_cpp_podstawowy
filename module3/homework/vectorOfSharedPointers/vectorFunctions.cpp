#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    if (count < 0) {
        return std::vector<std::shared_ptr<int>>{};
    }
    std::vector<std::shared_ptr<int>> vec {};
    vec.reserve(count);
    for (int i = 0; i < count; ++i) {
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>>& vec) {
    for (const auto & sptr: vec) {
        std::cout << *sptr << '\n';
    }
}

void add10(std::vector<std::shared_ptr<int>>& vec) {
    for (auto& elem : vec) {
        if(elem.get()) {
            *elem += 10;
        }
    }
}

void sub10(int * const ptr) {
    if (!ptr) {
        return;
    }
    *ptr -= 10;
}

void sub10(std::vector<std::shared_ptr<int>>& vec) {
    for (auto& elem : vec) {
        sub10(elem.get());
    }
}
