#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int sum = vec[0];
    for (const auto & ele : vec){
        if (sum < ele){
            sum = ele;
        }
    }
    return sum;
}
