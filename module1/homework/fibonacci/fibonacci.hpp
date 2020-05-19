#pragma once

int fibonacci_iterative(int sequence) {
    int fib1 = 0;
    int fib2 = 1;
    int result;
    if(sequence <= 1) 
        return sequence;

    for (int i = 2; i <= sequence; i++){
        result = fib1 +  fib2;
        fib1 = fib2;
        fib2 = result;
    }

    return result;

}

int fibonacci_recursive(int sequence) {
    if(sequence <= 1) 
        return sequence;
    return (fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
}
