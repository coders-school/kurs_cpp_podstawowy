#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vector{};
    if (count <= 0) {
        return vector;
    }
    vector.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vector.push_back(std::make_shared<int>(i));
    }
    return vector;
}

void print(const std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& el : vector) {
        std::cout << *el << " ";
    }
}

void add10(std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& el : vector) {
        if (el) {
            *el += 10;
        }
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& el : vector) {
        if (el) {
            sub10(el.get());
        }
    }
}

void sub10(int *const el) {
    if (el) {
        *el -= 10;
    }
}