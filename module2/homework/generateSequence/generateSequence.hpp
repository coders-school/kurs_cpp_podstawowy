#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence;
    if (count <= 0) {
        return sequence;
    }
    for (int i = 0; i < count; i++) {
        if (i == 0) {
            sequence.push_back(step);
        } else {
            sequence.push_back(sequence[i - 1] + step);
        }
    }

    return sequence;
}
