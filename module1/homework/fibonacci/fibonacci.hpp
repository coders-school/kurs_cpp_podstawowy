#pragma once
#include <vector>
#include <iostream>

int fibonacci_iterative(int sequence)
{
    if (sequence == 0)
    {
        return 0;
    }
    if (sequence == 1 || sequence == 2)
    {
        return 1;
    }

    std::vector<int> elements(2, 1);

    for (int i = 2; i < sequence; i++)
    {
        std::vector<int>::iterator it = elements.end();
        it--;
        auto lastVal = *it;
        it--;
        auto nextToLastVal = *it;
        auto sum = lastVal + nextToLastVal;
        elements.emplace_back(sum);
    }
    return elements.back();
}

int fibonacci_recursive(int sequence)
{
    if (sequence == 1 || sequence == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    }
}
