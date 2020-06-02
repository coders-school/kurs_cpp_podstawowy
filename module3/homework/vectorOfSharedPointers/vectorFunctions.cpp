#include "vectorFunctions.hpp"

void print(const std::vector<std::shared_ptr<int>> &vec){
    for(const auto &el : vec){
        std::cout << el;
    }
}

void sub10(int* const ptr){
    if(ptr){
        *ptr-=10;
    }
}

