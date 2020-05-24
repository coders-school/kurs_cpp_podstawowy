#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if(count <= 0) return std::vector<int>{};
    auto next_elem = step;
    std::vector<int> sequence{};
    sequence.reserve(count);
    for(int i = 0; i < count; i++)
    {
        sequence.push_back(next_elem);
        next_elem += step;
    }
    return sequence;
}
