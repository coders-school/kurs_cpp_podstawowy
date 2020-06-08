#pragma once
#include <vector>
#include <limits>

/**
 * Warning: 32bit architecture assumed.
 */
int maxOfVector(const std::vector<int>& vec) {
    int max = INT32_MIN;
    
    for (auto elem : vec){
        if(elem > max){
            max = elem;
        }
    }
    return max;
}
