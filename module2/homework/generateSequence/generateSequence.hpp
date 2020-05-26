#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> vec{step};
    for (const auto &it :vec){
        vec.push_back(step * (1 + it));
    }
    return {};
}