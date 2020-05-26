#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if(count<=0){
        return {};
    }
    std::vector<int> sequence;
    sequence.reserve(count);
    for(size_t i = 0; i<count; i++){
        sequence.push_back(step*(i+1));
    }
    return sequence;
}
