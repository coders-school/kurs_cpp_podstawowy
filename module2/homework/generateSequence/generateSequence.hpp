#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence;
    int add = step;

    for(int i = 0; i < count; ++i) {
        sequence.push_back(step);
        step += add;
    }

    return sequence;
}
