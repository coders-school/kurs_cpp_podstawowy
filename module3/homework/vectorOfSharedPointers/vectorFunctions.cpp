#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> sharedVector{};
    if (count <= 0) {
        return sharedVector;
    }
    sharedVector.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        sharedVector.push_back(std::make_shared<int>(i));
    }
    return sharedVector;
}

void print(const std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& ptr : vector) {
        std::cout << *ptr << "\n";
    }
}

void add10(const std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& ptr : vector) {
        if (ptr) {
            *ptr += 10;
        }
    }
}

void sub10(int* const ptr) {
    if (ptr) {
        *ptr -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vector) {
    for (const auto& ptr : vector) {
        sub10(ptr.get());
    }
}
