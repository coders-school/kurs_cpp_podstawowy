#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    int fib1 = 0;
    int fib2 = 1;
    int retval;

    if(0 == sequence) return 0;
    if(1 == sequence) return 1;
    
    for (int i = 2; i <= sequence; i++){
        retval = fib1 +  fib2;
        fib1 = fib2;
        fib2 = retval;
    }
    return retval;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    if(0 == sequence) return 0;
    if(1 == sequence) return 1;
    return (fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
}
