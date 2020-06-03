#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> pointers;
    int i = 0;
    while(i < count + 1){
        auto ptr = std::make_shared<int>(i);
        pointers.push_back(ptr);
        i++;
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
        *el = *el + 10;
    }
}
void sub10(std::shared_ptr<int>& ptr){
    *ptr = *ptr - 10;
}
void sub10(std::vector<std::shared_ptr<int>>& vec){
    for(auto& el: vec){
        sub10(el);
    }
}