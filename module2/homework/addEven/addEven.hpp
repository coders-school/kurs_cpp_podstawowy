#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers)
{
    int sumOfEven = 0;
    for (const auto& num : numbers)
    {
        if (!(num % 2))
        {
            sumOfEven += num;
        }
    }
    
    return sumOfEven;
}
