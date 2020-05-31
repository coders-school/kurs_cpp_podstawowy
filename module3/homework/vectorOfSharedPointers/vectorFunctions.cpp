#include "vectorFunctions.hpp"
#include <iostream>


std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> pointers(count);
    for(size_t i = 0; i < count; i++)
        pointers[i] = std::make_shared<int>(i);
    
    return pointers;
}

void print(const std::vector<std::shared_ptr<int>>& numbers) {
    for(const auto& num : numbers)
        std::cout << *num << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& numbers) {
    for(auto& num : numbers){
        if(num)
            *num+=10;
    }
}

void sub10(int* const number) {
    if(number)
        *number-=10;    
}

void sub10(const std::vector<std::shared_ptr<int>>& numbers) {
    for(auto& num : numbers){
        if(num)
            sub10(num.get());
    }
}
