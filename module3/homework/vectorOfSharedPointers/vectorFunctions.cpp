#include "vectorFunctions.hpp"

void print(const std::vector<std::shared_ptr<int>> &vec){
    for(const auto &el : vec){
        std::cout << el;
    }
}

void sub10(int* const ptr){
    if(ptr){
        *ptr-=10;
    }
}

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> result;
    for(int i=0;i<count;++i){
        result.emplace_back(std::make_shared<int>(i));
    }
    return result;
}

void sub10(std::vector<std::shared_ptr<int>> &vec){
    for(const auto & el: vec){
        if(el){
            sub10(el.get());
        }
    }
}

void add10(std::vector<std::shared_ptr<int>> &vec){
    for(const auto & el : vec){
        if(el){
            *el += 10;
        }
    }
}
