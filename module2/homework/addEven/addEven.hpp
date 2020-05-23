#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers)
{
    int sumOfEvenNumbers = 0;
    for (auto i = numbers.begin(); i != numbers.end(); ++i)
    {
        if ((*i >= 2 || *i <= -2) && (*i % 2 == 0))
        {
            sumOfEvenNumbers += *i;
        }
    }
    return sumOfEvenNumbers;
}
