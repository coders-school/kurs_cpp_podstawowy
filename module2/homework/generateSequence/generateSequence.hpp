#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if (count<=0) {return {0};}
    else if (step<=0) {return {};}
    else {
        std::vector<int> vec {step};
        for (int i=1; i<count; i++){
            vec.push_back(step * (1 + i));
        }
     return vec;
    }
}