#pragma once

int fibonacci_iterative(int sequence) {
   
    int result = 0;
    int first = 0;
    int second = 1;

    for(int i = 0; i < sequence; i++)
    {   
        first = second;
        second = result;
        result = second + first;
    }

    return result;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0) return 0;
    if (sequence == 1) return 1;
    
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
