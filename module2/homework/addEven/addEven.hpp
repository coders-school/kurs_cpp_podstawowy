#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int sum = 0;
    for (auto i = 0; i < numbers.size(); i++)
    {
        if (numbers[i]%2 == 0) sum += numbers[i];
    }
    return sum;
}
