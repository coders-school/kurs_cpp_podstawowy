#pragma once
#include <vector>
#include <limits>
#include <algorithm>

int maxOfVector(const std::vector<int>& vec) {
    // TODO: Implement me :)
    int max_number = vec[0];
    for (const auto& number : vec) {
        if(number >= max_number) {
            max_number = number;
        }
    }
    return max_number;
}
