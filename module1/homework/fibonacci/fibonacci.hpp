#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here    
    int result = 0;
    int next = 1;

    for (int i = 0; i < sequence; ++i){
        int tmp = result;
        result = next;
        next += tmp;
    }
    return result;
}

int fibonacci_recursive(int sequence, int result = 0, int next = 1) {
    // TODO: Your implementation goes here
    if (sequence <= 0){
        return result;
    }
    return fibonacci_recursive(sequence - 1, next, result + next);
}
    