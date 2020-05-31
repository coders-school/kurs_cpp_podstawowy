#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> newVector(count);
    for(int i = 0; i<count; ++i){   
        newVector[i] = std::make_shared<int>(i);
    }
    return newVector;
}

void print(const std::vector<std::shared_ptr<int>>& vec){
    for(const auto& element : vec)
        std::cout<<*element<<" ";
    std::cout<<'\n';
}

void add10(std::vector<std::shared_ptr<int>>& vec){
    for(auto& element : vec){
        if(element != nullptr)
           *element += 10;
    }
}

void sub10(int* const ptr){
    if(ptr != nullptr)
        *ptr -= 10;
}

void sub10(const std::vector<std::shared_ptr<int>>& vec){
    for(const auto& element : vec)
    {
        if(element != nullptr)
            *element -= 10;
    }
}
