#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> result_vector;
    if (count <= 0) {
        return result_vector;
    }
    for (size_t i = 1; i <= count; i++) {
        result_vector.push_back(i * step);
    }
    return result_vector;
}
