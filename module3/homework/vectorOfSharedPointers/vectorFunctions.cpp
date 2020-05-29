#include "vectorFunctions.hpp"
#include <vector>
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count){

    std::vector <std::shared_ptr<int>> SPvec;

    for(int i=0; i<count; i++){
        SPvec.push_back(std::make_shared<int>(i));
    }

    return SPvec;

}


void print(std::vector<std::shared_ptr<int>> pSPvec){
    // for ranged loop
    for(auto element : pSPvec){
        std::cout << element;
    }
}


void add10(std::vector<std::shared_ptr<int>> addSPvec){
    
    

    for(auto element : addSPvec){
        if(element.get()==nullptr)
            break;
        *element+=10;
    }

}
void sub10(int * const ptr){

    if(ptr==nullptr)
        return;
    *ptr-=10;


}
void sub10(std::vector<std::shared_ptr<int>> subSPvec){
    

    for(auto element : subSPvec){
        if(element.get()==nullptr)
            break;
        *element-=10;
    }

}