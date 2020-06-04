#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    auto max =  std::numeric_limits<int>::min();;

    for (const auto& el : vec) {
        el > max ? max = el : 0;
    }
    return max;
}
