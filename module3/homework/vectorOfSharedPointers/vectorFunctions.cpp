#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count){

    std::vector<std::shared_ptr<int>> vec{};
    for(int i = 0; i<count; i++){
        vec.push_back(std::make_shared<int>(i));
    }

return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec){
    for(auto element : vec){
        std::cout << *element << std::endl;
    }
}

void add10(std::vector<std::shared_ptr<int>>& vec){
    for(auto element : vec){
        if(element != nullptr)
            *element += 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vec){
     for(auto element : vec){
        if(element != nullptr)
            *element -= 10;
    }
}

void sub10(int * const element){
    if(element != nullptr)
        *element -= 10;
}
