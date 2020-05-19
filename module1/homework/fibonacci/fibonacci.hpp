#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence < 0) {
        return -1;
    }
    int fib[sequence + 1];
    fib[0] = 0;
    if (sequence > 0) {
        fib[1] = 1;
    }
    for (int i = 2; i < sequence + 1; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[sequence];
}

int fibonacci_recursive(int sequence) {
    return 0;
}
