#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence == 0) {
        return 0;
    }

    if (sequence == 1) {
        return 1;
    }

    int result = 0, first = 0, second = 1;
    for (size_t i = 2; i <= sequence; i++) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0) {
        return 0;
    }
    if(sequence == 1) {
        return 1;
    }
    return fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1);
}
