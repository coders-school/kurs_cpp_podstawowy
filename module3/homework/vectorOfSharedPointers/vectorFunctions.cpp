#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> pointers;
    pointers.reserve(count);
    
    
    for(int i = 0; i < count; i++){
        auto ptr = std::make_shared<int>(i);
        pointers.push_back(ptr);
    }
    
    return pointers;
}
void print(const std::vector<std::shared_ptr<int>>& vec){
    for(auto const& el: vec){
        std::cout << *el << "\n";
    }
}
void add10(const std::vector<std::shared_ptr<int>>& vec){
    for(const auto& el: vec){
        if(el){
            *el += 10;
        }
    }
}
void sub10(int * const ptr){
    if(ptr){
        *ptr -= 10;
    }
}
void sub10(const std::vector<std::shared_ptr<int>>& vec){
    for(const auto& el: vec){
        sub10(el.get());
    }
}
