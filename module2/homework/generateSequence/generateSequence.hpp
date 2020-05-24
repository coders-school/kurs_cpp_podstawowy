#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> vec;    
    auto currentValue = step;

    for (auto i = 0; i < count; i++) {
        vec.push_back(currentValue);
        currentValue += step;
    }

    return vec;
}
