#pragma once
#include <iostream>

int fibonacci_iterative(int sequence)
{

    auto tmp = 0;
    auto first_ = 0;
    auto second_ = 1;

    if (sequence == 0)
        return 0;
    else if (sequence == 1)
        return 1;
    else if (sequence > 2)
    {
        for (int i = 1; i < sequence; i++)
        {
            tmp = second_;
            second_ = second_ + first_;
            first_ = tmp;
        }
    }
    return second_;
}

int fibonacci_recursive(int sequence)
{
    if (sequence == 0)
        return 0;
    else if (sequence == 1)
        return 1;
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
