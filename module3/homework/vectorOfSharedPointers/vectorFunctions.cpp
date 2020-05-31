#include <iostream>

#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(const int count) {
    std::vector<std::shared_ptr<int>> vec(count);

    for (auto i = 0; i < count; i++) {
        vec[i] = std::make_shared<int>(i);
    }
    return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto &el : vec) {
        if (el != nullptr) {
            std::cout << *el << ' ';
        }
    }
    std::cout << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto &el : vec) {
        if (el != nullptr) {
            *el += 10;
        }
    }
}

void sub10(int* const num) {
    if (num != nullptr) {
        *num -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto &el : vec) {
        sub10(el.get());
    }

}
