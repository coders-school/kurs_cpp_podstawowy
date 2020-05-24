#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence;

    if (count <= 0) {
        return sequence;
    }

    sequence.resize(count);

    sequence[0] = step;
    for (int i = 1; i < count; i++) {
        sequence[i] = sequence[i - 1] + step;
    }

    return sequence;
}
