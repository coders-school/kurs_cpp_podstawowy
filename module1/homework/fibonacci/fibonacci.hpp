#pragma once

int fibonacci_iterative(int sequence) {
    int fib_tmp = 0, fib_current = 0, fib_next = 1;
    for(int i = 0; i < sequence; i++)
    {
        fib_tmp = fib_current + fib_next;
        fib_current = fib_next;
        fib_next = fib_tmp;
    }
    return fib_current;
}

int fibonacci_recursive(int sequence) {
    return 0;
}