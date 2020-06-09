#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count){

    std::vector <std::shared_ptr<int>> SPvec;
    for(int i=0; i<count; i++){
        SPvec.push_back(std::make_shared<int>(i));
    }
    return SPvec;
}


void print(const std::vector<std::shared_ptr<int>>& pSPvec){

    for(const auto& element : pSPvec){
        std::cout << element;
    }
}


void add10(const std::vector<std::shared_ptr<int>>& addSPvec){
    
    for(auto element : addSPvec){
        if(!element.get())
            continue;
        *element+=10;
    }

}
void sub10(int * const ptr){

    if(ptr==nullptr)
        return;
    *ptr-=10;
}

void sub10(const std::vector<std::shared_ptr<int>>& subSPvec){
    
    for(auto element : subSPvec){
        if(!element.get())
            continue;
        sub10(element.get());
    }
}
