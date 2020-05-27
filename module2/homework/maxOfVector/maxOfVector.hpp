#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max = std::numeric_limits<int>::min();
    for (auto element : numbers) {
        if(element > max){
            max = element;
        }
    }
    return max;
}
