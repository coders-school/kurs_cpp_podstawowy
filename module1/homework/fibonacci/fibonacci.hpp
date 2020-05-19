#pragma once

int fibonacci_iterative(int sequence) {
    int first = 0;
    int second = 1;
    int temp;

    if (sequence == 0)
        return first;
    if (sequence < 2)
        return second;

    for (int i = 1; i < sequence; ++i)
    {
        temp = first + second;
        first = second;
        second = temp;        
    }

    return temp;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0)
        return 0;
    if (sequence < 3)
        return 1;

    return fibonacci_recursive(sequence - 2) +
        fibonacci_recursive(sequence - 1);
}