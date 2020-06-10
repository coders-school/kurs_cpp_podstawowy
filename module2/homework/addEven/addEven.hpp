#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) 
{
    int sum{};
    for (const auto& el: numbers)
    {
        if(el%2==0)
        sum=sum+el;
    }
    return sum;
}
