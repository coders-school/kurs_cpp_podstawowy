#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int sum = 0;
    for (const auto& ele : numbers){
        if (ele % 2 == 0){
            sum += ele;
        }
    }
    return sum;
}
