#pragma once

int fibonacci_iterative(int sequence) {
    if(sequence == 0) {
        return 0;
    }
    if(sequence < 3) {
        return 1;
    } else {
        int minus_two = 1;
        int minus_one = 1;
        int fib = 2;
        for(int i = 4; i <= sequence; i++) {            
            minus_two = minus_one;
            minus_one = fib;
            fib = minus_two + minus_one;
        }
        return fib;
    }
}

int fibonacci_recursive(int sequence) {
    if(sequence < 1) {return 0;}    
    return (sequence < 3) ? 1 : fibonacci_recursive(sequence - 1) + 
        fibonacci_recursive(sequence - 2);
}