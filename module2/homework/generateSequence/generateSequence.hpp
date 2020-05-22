#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    // TODO: Implement me :)
    std::vector<int> vec;
    int move = step;

    for(int i = 0; i <count; i++){
        vec.push_back(move);
        move += step;
    }

    return vec;
}