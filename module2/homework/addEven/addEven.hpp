#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) 
{
    int sum = 0;

    for (auto number : numbers) 
    {
        if(0 == number%2) 
        {
            sum += number;
        }
    }
    return sum;
}
