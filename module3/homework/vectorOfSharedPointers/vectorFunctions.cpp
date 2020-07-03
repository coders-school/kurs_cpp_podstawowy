#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> returnValue;
    if (count <= 0) {
        return returnValue;
    }
    returnValue.reserve(count);
    for(int i = 0; i < count; ++i) {
        returnValue.emplace_back(std::make_shared<int>(i));
    }
    return returnValue;
}

void print(const std::vector<std::shared_ptr<int>>& input) {
    for(const auto& element : input) {
        if (element) {
            std::cout << *element << '\n';
        } else {
            std::cerr << "Element in vector is a nullptr!\n";
        }
    }
}

void add10(std::vector<std::shared_ptr<int>>& input) {
    for(auto& element : input) {
        if(element) {
            *element += 10;
        }
    }
}

void sub10(int* const input) {
    if(input) {
        *input -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& input) {
    for(auto & element : input) {
        sub10(element.get());
    }
}
