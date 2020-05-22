#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if(count < 1) {
        return {};
    }
    int number = step;
    std::vector<int> sequence;

    for(int i = 1; i <= count; i++) {
        number = step * i;
        sequence.push_back(number);
    }

    return sequence;
}
