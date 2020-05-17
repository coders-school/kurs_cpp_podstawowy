#pragma once

int fibonacci_iterative(int sequence)
{
    // TODO: Your implementation goes here
    int current = 0, next = 1, tmp = 0;
    for (int i = 0; i < sequence; i++)
    {
        tmp = current + next;
        current = next;
        next = tmp;
    }
    return current;
}

int fibonacci_recursive(int sequence)
{
    // TODO: Your implementation goes here
    if (sequence <= 1)
        return sequence;
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
