#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    
    int result;

    if (vec.size() > 0) {
        result = vec[0];
    }
    else {
        return -1;
    }

    for (const auto& value : vec) {
        if (value > result) {
            result = value;
        }
    }

    return result;
}
