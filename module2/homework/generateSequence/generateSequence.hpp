#pragma once
#include <vector>
#include <iostream>

std::vector<int> generateSequence(int count, int step) {    
    if (count < 1) {
        return std::vector<int> {};
    }
    
    std::vector<int> result(count, step);

    for (size_t i = 1; i < count; ++i) {
        result[i] += step * i;
    }

    // TODO: Implement me :)
    return result;
}
