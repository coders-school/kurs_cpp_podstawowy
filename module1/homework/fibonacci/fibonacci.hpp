#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    int pre_previous = 0;
    int previous = 1;
    int current = 0;
    if (sequence == 0) {
        return pre_previous;
    } else if (sequence == 1) {
        return previous;
    }
    for (int i = 1; i < sequence; ++i) {
        current = pre_previous + previous;
        pre_previous = previous;
        previous = current;
    }
    return current;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    if (sequence <= 1) {
        return sequence; 
    } else {
        return fibonacci_recursive(sequence - 1) + 
               fibonacci_recursive(sequence - 2);
    }
}
