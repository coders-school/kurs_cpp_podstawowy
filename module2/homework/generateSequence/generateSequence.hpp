#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if (count <= 0) {
        return {};
    }
    std::vector<int> vec {step};
    vec.reserve(count);
    for (auto it = 1; it < count; it++) {
        vec.emplace_back(vec[it - 1] + step);
    }

    return vec;
}
