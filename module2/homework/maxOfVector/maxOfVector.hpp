#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    if(vec.size() == 0) return 0;
    int tmp = vec[0];
    for(const auto &number : vec){
        if(number > tmp)
            tmp = number;
    }
    return tmp;
}
