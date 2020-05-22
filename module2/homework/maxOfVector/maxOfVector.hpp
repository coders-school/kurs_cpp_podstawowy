#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max;
    max = vec[0];

    for(const auto& i : vec) {
        if(i > max) {
            max = i;
        }
    }
    return max;
}
