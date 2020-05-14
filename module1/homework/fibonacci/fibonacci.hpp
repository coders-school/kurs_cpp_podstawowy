#pragma once

int fibonacci_iterative(int sequence)
{
    
    return 0;
}

int fibonacci_recursive(int sequence)
{
    if ((sequence == 0) || (sequence == 1))
    {
        return sequence;
    }

    return (fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
}
