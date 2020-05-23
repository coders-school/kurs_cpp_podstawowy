#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    auto maximal = vec[0];
    for(const auto& el : vec){
        if(el > maximal){
            maximal = el;
        }
    }

    return maximal;
}
