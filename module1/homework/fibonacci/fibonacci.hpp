#pragma once

int fibonacci_iterative(int sequence) {
    
    int fib = 0, fib1 = 1, fib2 = 1;
    if (sequence == 0 || sequence == 1) return sequence;
    for(int i=2; i < sequence; i++)
    {
        fib = fib1;
        fib1 = fib2;
        fib2 += fib;
    }
    return fib2;
}

int fibonacci_recursive(int sequence) {

    if (sequence == 0 || sequence == 1) return sequence;
    return fibonacci_recursive(sequence-1)+fibonacci_recursive(sequence-2);
  
}
