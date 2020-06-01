#include "vectorFunctions.hpp"

#include <algorithm>
#include <functional>
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

struct Add10 {
    int number;
    Add10(int numToAdd)
        : number(numToAdd) {}

    void operator()(const std::shared_ptr<int>& elem) const {
        auto el = elem.get();
        el += number;
    }
};

void add10(const std::vector<std::shared_ptr<int>>& vec) {
    if (vec.empty()) {
        return;
    }
    const int numToAdd = 10;
    std::for_each(vec.begin(), vec.end(), Add10(numToAdd));
}

void sub10(const std::vector<std::shared_ptr<int>>& vec) {
    if (vec.empty()) {
        return;
    }
    for (const auto& elem : vec) {
        auto ptr = elem.get();
        sub10(ptr);
    }
}