#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers)
{
    int evenNumbersAmount = 0;
    for (auto i = numbers.begin(); i != numbers.end(); ++i) {
        if (*i >= 2 && *i % 2 == 0)
        {
            evenNumbersAmount++;
        }
    }
    return evenNumbersAmount;
}
