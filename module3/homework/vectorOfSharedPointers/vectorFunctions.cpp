#include "vectorFunctions.hpp"

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
void add10(std::vector<std::shared_ptr<int>>& vec){
    for(auto& el: vec){
        if(el == nullptr){
            break;
        }
        *el = *el + 10;
    }
}
void sub10(int * ptr){
    if(ptr != nullptr){
        *ptr = *ptr - 10;
    }
}
void sub10(std::vector<std::shared_ptr<int>>& vec){
    for(auto& el: vec){
        int * ptr = el.get();
        sub10(ptr);
    }
}
