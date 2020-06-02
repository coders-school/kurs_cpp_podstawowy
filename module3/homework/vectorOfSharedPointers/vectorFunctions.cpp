#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; i++) {
        vec.push_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>>& vector) {

}

void add10(std::vector<std::shared_ptr<int>>& vector) {

}

void sub10(int* const ptr) {

}

void sub10(std::vector<std::shared_ptr<int>>& vector) {

}