#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max=std::numeric_limits<int>::min();
    for (const auto& el : vec) {
        if (el>max) {
            max=el;
        }
    }
    return max;
}
