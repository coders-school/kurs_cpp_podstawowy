#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {

    if (count < 0) {
        return {};
    }

    std::vector<int> vec(count);

    int currentNum = step;

    for(auto& element : vec) {
        element = currentNum;
        currentNum += step;
    }
    return vec;
}

