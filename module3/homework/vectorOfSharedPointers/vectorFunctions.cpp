#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; i++) {
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& el : vector) {
        std::cout << *el << "\n";
    }
}

void add10(std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& el : vector) {
        if (el) {
            *el += 10;
        }
    }
}

void sub10(int* const ptr) {
    if (ptr) {
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& el : vector) {
        sub10(el.get());
    }
}
