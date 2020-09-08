#pragma once
#include <limits>
#include <vector>

int maxOfVector(const std::vector<int>& vec) {
    int max = std::numeric_limits<int>::min();
    
    for (const int element : vec) {
        if (element > max) {
            max = element;
        }
    }

    return max;
}
