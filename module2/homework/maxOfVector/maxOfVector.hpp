#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max = vec.front();
    for (const auto& element : vec) {
        if (max < element) {
        max = element;
        }
    }
    return max;
}