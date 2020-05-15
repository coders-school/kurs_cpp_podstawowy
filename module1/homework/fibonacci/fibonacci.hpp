#pragma once

int fibonacci_iterative(int sequence)
{
    // TODO: Your implementation goes here
    if (sequence <= 1)
    {
        return sequence;
    }
    int fibo = 0;
    int before_last = 0;
    int last = 1;
    for (int i = 2; i <= sequence; ++i)
    {
        fibo = (before_last + last);
        before_last = last;
        last = fibo;
    }
    return fibo;
}

int fibonacci_recursive(int sequence)
{
    // TODO: Your implementation goes here
    if (sequence <= 1)
    {
        return sequence;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
