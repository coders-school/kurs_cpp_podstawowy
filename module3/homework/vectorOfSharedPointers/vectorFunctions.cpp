#include <iostream>

#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count){
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);
    for(int i = 0; i < count; i++){
        vec.push_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec){
    for(const auto& el : vec){
        std::cout << "element:" << *el << std::endl;
    }
}

void add10(std::vector<std::shared_ptr<int>>& vec){
    for(const auto& el : vec){
    	if(el){
        	*el += 10;
        }
    }
}

void sub10(int* const ptr){
    if(ptr){
	*ptr -= 10;
    }
}

void sub10(const std::vector<std::shared_ptr<int>>& vec){
    for(const auto& el : vec){
    	if(el){
        	sub10(el.get());
	}
    }
}


