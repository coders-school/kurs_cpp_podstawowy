#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {    
    if(vec.size() == 0) {
        return 0;
    }
    int max = std::numeric_limits<int>::min();

    for(auto elem : vec) {
        if(elem > max) {
            max = elem;
        }
    }
    return max;
}
