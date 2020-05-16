#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    return 0;
}

int fibonacci_recursive(int sequence, int result = 0, int next = 1) {
    // TODO: Your implementation goes here
    if (sequence <= 0){
        return result;
    }
    return fibonacci_recursive(sequence-1, next, result+next);
}


    