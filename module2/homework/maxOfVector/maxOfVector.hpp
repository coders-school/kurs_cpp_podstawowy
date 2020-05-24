#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {

    if (vec.empty()) {
        return 0;
    }

    int max = vec[0];

    for (const auto& el : vec) {
        if (el > max) {
            max = el;
        }
    }
    return max;
}
