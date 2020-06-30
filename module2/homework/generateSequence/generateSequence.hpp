#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> returnVec{};
    if(count <= 0) {
        return returnVec;
    }
    
    returnVec.reserve(count);
    
    for(int actualValue = 0, i = 0; i < count; ++i) {
        actualValue += step;
        returnVec.push_back(actualValue);
    }
    
    return returnVec;
}
