#include "vectorFunctions.hpp"

#include <iostream>

std::vector <std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result;
    result.reserve(count);
    for(auto i = 0; i < count; ++i)
        result.emplace_back(std::make_shared<int>(i));

    return result;
}

void print(const std::vector <std::shared_ptr<int>> vec) {
    for (auto element : vec)
        if (element)
            std::cout << *element << " ";
    std::cout << std::endl;
}

void add10(std::vector <std::shared_ptr<int>> vec) {
    for (auto element : vec)
        if (element)
            *element += 10;
}

void sub10(int* number) {
    if (number)
        *number -= 10;
}

void sub10(std::vector <std::shared_ptr<int>> vec) {
    for (auto element : vec)
        if (element)
            sub10(element.get());
}
