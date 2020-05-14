#pragma once

int fibonacci_iterative(int sequence)
{
    if ((sequence == 0) || (sequence == 1))
    {
        return sequence;
    }

    int prev = 0;
    int next = 1;
    int result;

    for(size_t i = 1; i < sequence; i++)
    {
        result = prev + next;
        prev = next;
        next = result;
    }

    return result;
}

int fibonacci_recursive(int sequence)
{
    if ((sequence == 0) || (sequence == 1))
    {
        return sequence;
    }

    return (fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
}
