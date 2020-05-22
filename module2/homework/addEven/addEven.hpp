#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    if(numbers.size() == 0) {
        return 0;
    }
    int sumOfEvenNumbers = 0;
    for(auto elem : numbers) {
        if(!(elem & 0x1)) {
            sumOfEvenNumbers += elem;
        }
    }
    return sumOfEvenNumbers;
}
