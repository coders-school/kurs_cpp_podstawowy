#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> generatedVec {};
    for(int i = 0; i < count; ++i){
        generatedVec.emplace_back(step*(i+1));
    }
    return generatedVec;
}
