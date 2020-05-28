#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max_number = vec[0];
    for (const auto& number : vec) {
        if (number >= max_number) {
            max_number = number;
        }
    }
    return max_number;
}
