#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    if (count <= 0){
        return std::vector<int>{};
    }
    std::vector<int> result(count);
    int sum = 0;
    for (int i = 1;i <= count;i++){
        sum += step;
        result[i - 1] = sum;
    }
    return result;
}
