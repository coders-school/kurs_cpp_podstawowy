#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) 
{
    int result = 0;

    for (auto number : numbers)
    {
        number % 2 == 0 ? result += number : 0;
    }

    return result;
}
