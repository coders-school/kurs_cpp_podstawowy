#pragma once
#include <vector>
#include <iostream>
std::vector<int> generateSequence(int count, int step){
    if(count <= 0){
        return {};
    }
    std::vector<int> vec {step};
    vec.reserve(count);
    for(auto i = 2; i < count + 1; i++){
        vec.push_back(step * i);
    }
    return vec;
}
