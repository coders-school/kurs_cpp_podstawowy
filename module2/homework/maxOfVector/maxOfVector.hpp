#pragma once
#include <vector>
#include <limits>
#include <algorithm>

int maxOfVector(const std::vector<int>& vec) {
    
    int result = *std::max_element(vec.begin(), vec.end());

    return result;
}
