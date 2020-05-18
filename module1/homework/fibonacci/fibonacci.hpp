#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence < 2) {
        return sequence;
    } else {
        int fib_n_2 = 0;
        int fib_n_1 = 1;
        int fib_n;

        for (auto i = 2; i <= sequence; i++) {
            fib_n = fib_n_1 + fib_n_2;

            fib_n_2 = fib_n_1;
            fib_n_1 = fib_n; 
        }
        return fib_n;
    }
}

int fibonacci_recursive(int sequence) {
    return (sequence < 2 ? sequence : fibonacci_recursive(sequence -2) + 
                                      fibonacci_recursive(sequence - 1));
}
