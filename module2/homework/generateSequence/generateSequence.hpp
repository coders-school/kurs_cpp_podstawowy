#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence;

    if (count <= 0) {
        return sequence;
    }

    sequence.push_back(step);
    for (int i = 1; i < count; i++) {
        sequence.push_back(sequence[i - 1] + step);
    }

    return sequence;
}
