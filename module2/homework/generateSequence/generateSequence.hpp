#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step){
    if(count <= 0){
        return{};
    }
    std::vector<int> vec;
    vec.reserve(count);
    for(auto i = 1; i <= count; i++){
        vec.push_back(step * i);
    }
    return vec;
}
