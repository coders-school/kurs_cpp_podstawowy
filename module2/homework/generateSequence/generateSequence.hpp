#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> result;
    for(int i = 1;i <= count;i++){
        result.push_back(step * i);
    }
    return result;
}
