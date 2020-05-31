#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence;
    for(int i = 0; i < count; i++) {
        sequence.push_back((i+1)*step);
    }
    return sequence;
}
