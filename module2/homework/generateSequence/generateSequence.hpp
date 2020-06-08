#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> sequence;
    int sum = step;
    if(count > 0){
        for(int i= 0; i < count; i++){   
            sequence.push_back(sum);
            sum += step;
        }
    }
    return sequence;
}
