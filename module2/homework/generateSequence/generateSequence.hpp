#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
        if (count<0) {
        return {};
    }
    std::vector<int> vec(count);
    for (int i=0; i<count; i++){
        vec[i]=(i+1)*step;
    }
    return {vec};
}
