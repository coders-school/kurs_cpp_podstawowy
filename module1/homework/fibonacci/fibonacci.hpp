#pragma once

long int fibonacci_iterative(int sequence) {
    if(sequence == 0)return 0;
    if(sequence == 1)return 1;
    long int fib[sequence];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= sequence; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[sequence];
}

long int fibonacci_recursive(long int sequence) {
    if(sequence == 0) return 0;
    if(sequence == 1 || sequence == 2)return 1;
    sequence = fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    return sequence;
}
