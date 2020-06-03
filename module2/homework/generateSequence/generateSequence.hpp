#pragma once
#include <vector>

std::vector<int> generateSequence (int count, int step) {
    if (count <= 0) {
        return std::vector<int>{};
    }
    std::vector<int> result(count);
    int sum = 0;
    for (int i = 0;i < count;i++) {
        sum += step;
        result[i] = sum;
    }
    return result;
}
