#pragma once
#include <vector>

int maxOfVector(const std::vector<int>& vec){
    int maxValue = vec[0];
    for(const auto& element : vec){
        if(element > maxValue){
            maxValue = element;
        }
    }
    return maxValue;
}
