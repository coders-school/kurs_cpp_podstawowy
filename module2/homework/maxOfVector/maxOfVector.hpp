#pragma once
#include <vector>

int maxOfVector(const std::vector<int>& vec) {
    int maxValue = vec[0];
    for (auto i = 1; i < vec.size(); i++)
    {
        if (vec[i] > maxValue) maxValue = vec[i];
    }
    return maxValue;
}
