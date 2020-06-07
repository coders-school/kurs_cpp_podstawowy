#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> vec;
    for(size_t i = 0; i < (count); ++i){
        vec.emplace_back(std::make_shared<int>(i));
    }
    return vec;
}
void print(std::vector<std::shared_ptr<int>> vec){
    for(auto el : vec){
        std::cout << *el << "\n";
    }

}
void add10(std::vector<std::shared_ptr<int>>& vec){
    for(size_t i = 0; i < vec.size(); ++i){
       if(vec[i]){
        *vec[i] += 10;
       }
        else{
            std::cout << "Pointer is NullPtr";
        }

        
    }

}
void sub10(std::vector<std::shared_ptr<int>> vec){

}
void sub10(int* const ptr){

}
