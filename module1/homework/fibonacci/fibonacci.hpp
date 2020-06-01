#pragma once

int fibonacci_iterative(int sequence) {
    int fibonacciCurrent = 1, fibonacciN1 = 1, fibonacciN2 = 1;
    
    if (sequence == 0)
      return 0;
    
    for (auto iter = 3 ; iter <= sequence ; iter++) {
      fibonacciCurrent = fibonacciN1 + fibonacciN2;
      fibonacciN2      = fibonacciN1;
      fibonacciN1      = fibonacciCurrent;
    }
    
    return fibonacciCurrent;
}

int fibonacci_recursive(int sequence) {
    if(sequence < 0)
        return -1;
    else if ( sequence <= 1)
        return sequence;
        
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
