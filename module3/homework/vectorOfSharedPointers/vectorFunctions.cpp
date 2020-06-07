#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count)
{
    std::vector<std::shared_ptr<int>> vec{};
    if (count <= 0)
    {
        return vec;
    }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i)
    {
        vec.push_back(std::make_shared<int>(i));
    }
    return vec;
}
void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        std::cout << *el << " ";
    }
}
void add10(std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        if (el) {
            *el += 10;
        }
    }
}
void sub10(std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        if (el) {
            sub10(el.get());
        }
    }
}
void sub10(int* const el) {
    if (el) {
        *el -= 10;
    }
}
