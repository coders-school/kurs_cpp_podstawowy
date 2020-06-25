#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec;
    if (count <= 0) {
        return vec;
    }
    vec.reserve(count);
    for (size_t i = 0; i < count; i++) {
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& element : vec) {
        std::cout << *element << "\n";
    }
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& element : vec) {
        if (element) {
            *element += 10;
        }
    }
}

void sub10(int* const ptr) {
    if (ptr) {
        *ptr -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& element : vec) {
        sub10(element.get());
    }
}