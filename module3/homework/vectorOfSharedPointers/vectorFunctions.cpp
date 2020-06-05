#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(const int count) {
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for (int i = 0; i < count; i++) {
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}
void print(const std::vector<std::shared_ptr<int>>& vec) {
    std::cout << "{ ";
    for (const auto& el : vec) {
        std::cout << *el << " ";
    }
    std::cout << "}\n";
}
void add10(std::vector<std::shared_ptr<int>>& vec) {
    for (auto& el : vec) {
        if (el)
            *el += 10;
    }
}
void sub10(std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& el : vec) {
        if (el)
            sub10(el.get());
    }
}
void sub10(int* const el) {
    if (el)
        *el -= 10;
}
