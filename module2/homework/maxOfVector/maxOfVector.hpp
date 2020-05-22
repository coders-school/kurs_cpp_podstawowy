#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    // TODO: Implement me :)
    int max_value = vec.front();

    for(const int& elem : vec)
    {
        max_value = max_value <= elem ? elem : max_value;
    }

    return vec.size() == 0 ? 0 : max_value;
}
