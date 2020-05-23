#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if(count <= 0){
        return {};
    }
    
    std::vector<int> sequence(count, step);
    for(int i = 1; i < count; i++){
        sequence[i] += i * step;
    }
    return sequence;
}
