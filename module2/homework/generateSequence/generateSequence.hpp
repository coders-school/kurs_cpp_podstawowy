#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence {};

    if (count < 0) return sequence;

    sequence.reserve(count);
    
    for (std::size_t i = 0; i < count; ++i) {
	sequence.push_back(step * (i + 1));
    }

    return sequence;
}
