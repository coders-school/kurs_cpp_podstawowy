#pragma once

int fibonacci_iterative(int sequence)
{
    if (sequence == 0)
    {
        return 0;
    }
    else if (sequence <= 2)
    {
        return 1;
    }

    int results[sequence + 1];
    results[0] = 0;
    results[1] = 1;
    results[2] = 1;

    for (int i = 3; i <= sequence; ++i)
    {
        results[i] = results[i - 1] + results[i - 2];
    }
    return results[sequence];
}

int fibonacci_recursive(int sequence)
{
    if (sequence == 0)
    {
        return 0;
    }
    else if (sequence <= 2)
    {
        return 1;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
