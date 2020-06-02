#include "vectorFunctions.hpp"

#include <algorithm>
#include <functional>
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result;

    for (int i = 0; i < count; i++) {
        result.emplace_back(std::make_shared<int>(i));
    }

    return result;
}

void print(const std::vector<std::shared_ptr<int>>& vecToPrint) {
    std::cout << "Vectors elements: ";
    for (const auto& el : vecToPrint) {
        std::cout << *el << " ";
    }
    std::cout << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& ptr : vec) {
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

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& elem : vec) {
        if (elem) {
            sub10(elem.get());
        }
    }
}
