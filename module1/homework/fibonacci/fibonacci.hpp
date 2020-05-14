#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    int x = 0;
    int y = 1;
    int next = 0;
    if (sequence == 0) {
        return x;
    } else if (sequence == 1) {
        return y;
    }
    for (int i = 1; i < sequence; ++i) {
        next = x + y;
        x = y;
        y = next;
    }
    return next;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    if (sequence == 0) {
        return 0;
    } else if (sequence == 1 ) {
        return 1;  
    } else {
        return fibonacci_recursive(sequence - 1) + 
               fibonacci_recursive(sequence -2);
    }
}
