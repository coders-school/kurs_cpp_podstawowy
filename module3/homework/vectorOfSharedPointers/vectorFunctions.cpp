#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec;
    if (count <= 0) {
        return vec;
    }
    for (int i = 0; i < count; ++i) {
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    if (vec.empty()) {
        std::cerr << "Vector is empty.";
    }

    for (auto& el : vec) {
        std::cout << *el << " ";
    }

    std::cout << "\n";
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (auto& el : vec) {
        if (el) {
            *el += 10;
        }
    }
}

void sub10(int* const ptr) {
    if (ptr) {
        *ptr -= 10;
    } else {
        std::cerr << "Error";
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vec) {
    for (auto& el : vec) {
        sub10(el.get());
    }
}
