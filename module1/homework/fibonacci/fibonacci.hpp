#pragma once
#include<array>

int fibonacci_iterative(int sequence) 
{
    std::array<int, 2> prevFib = {0 ,0};
    int fib = 0;
    for(int i = 0; i < sequence; i++)
    {   
        if (i <= 0)
        {
            prevFib.at(0) = 1;
            fib = 1;
            continue;
        }
        else if (i == 1)
        {
            prevFib.at(1) = 1;
            continue;
        }
        fib = prevFib.at(0) + prevFib.at(1);
        prevFib.at(0) = prevFib.at(1);
        prevFib.at(1) = fib;
    }
    return fib;
}

int fibonacci_recursive(int sequence) 
{
    if (sequence <= 0)
        return 0;
    else if (sequence <= 2)
        return 1;
    else
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
