#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if(count <= 0)return std::vector<int>{};
    std::vector<int> vec;
    vec.reserve(count);
    int value = 0;
    for(auto i = 0 ; i < count ;i++){
    value += step;
    vec.push_back(value);
    }
    return vec;
}
