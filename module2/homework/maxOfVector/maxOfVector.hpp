#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    auto max = vec[0];
    for(const auto& elem : vec)
    {
        if(max < elem) max = elem;
    }
    return max;
}
