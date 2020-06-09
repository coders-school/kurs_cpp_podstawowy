#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for(size_t i = 0; i < count; ++i){
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}
void print(const std::vector<std::shared_ptr<int>>& vec){
    for(auto el : vec){
        std::cout << *el << "\n";
    }

}
void add10(const std::vector<std::shared_ptr<int>>& vec){
    for(size_t i = 0; i < vec.size(); ++i){
       if(vec[i]){
        *vec[i] += 10;
       }
        else{
            std::cout << "Nullptr" << "\n";
        }
        
    }
 
}
void sub10(const std::vector<std::shared_ptr<int>>& vec){
    for(size_t i = 0; i < vec.size(); ++i){
        if(vec[i]){
            sub10(vec[i].get());
        }
        else{
            std::cout << "Nullptr" << "\n";
        }
    }
}
void sub10(int* const ptr){
    if(ptr){
        *ptr -= 10;
    }
    else{
        std::cout << "Nullptr" << "\n";
    }
}
