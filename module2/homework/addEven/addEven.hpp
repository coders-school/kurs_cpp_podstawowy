#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int output = 0;
    for (const auto& el : numbers) {
        if (el % 2 == 0) {
            output += el;
        }
    }
    return output;
}
