#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max = INT32_MIN;
    for (const auto & elem : vec) {
        if(elem > max) {
            max = elem;
        }
    }
    return max;
}
