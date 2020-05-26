#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    if(vec.size() == 0) return 0;
    if(vec.size() == 1) return vec[0];
    int tmp = vec[1];
    for(auto number : vec){
        if(number > tmp)
            tmp = number;
    }
    return tmp;
}
