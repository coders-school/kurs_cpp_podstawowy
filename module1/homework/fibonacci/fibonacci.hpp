#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence < 2) return sequence;
    else
    {
        int fib1 = 0, fib2 = 1, temp;
        for (auto i = 2; i <= sequence; i++)
        {
            temp = fib2;
            fib2 += fib1;
            fib1 = temp;
        }
        return fib2;
    }
    
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0) return 0;
    if (sequence == 1) return 1;
    return (fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2));
}
