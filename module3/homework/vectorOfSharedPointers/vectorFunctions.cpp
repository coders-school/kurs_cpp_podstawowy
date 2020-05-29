#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result;

    for (int i = 0; i <= count; i++) {
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