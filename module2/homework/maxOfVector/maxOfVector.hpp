#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    if (vec.empty()) {
        return 0;
    }
    int maxVec = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (maxVec < vec[i]) {
            maxVec = vec[i];
        }
    }
    return maxVec;
}
