#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int sumEven = 0;
    for(const auto& i : numbers) {
        if(i % 2 == 0) {
            sumEven += i;
        }
    }

    return sumEven;
}
