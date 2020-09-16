#pragma once
#include <cstddef>

int fibonacci_recursive(int sequence) {
    if (sequence == 0 || sequence == 1) {
        return sequence;
    }

    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}

int fibonacci_iterative(int sequence) {
    if (sequence == 0 || sequence == 1) {
        return sequence;
    }

    int first = 0;
    int second = 1;
    for (size_t i = 1; i < sequence; ++i) {
        int tmp = second;
        second = first + second;
        first = tmp;
    }

    return second;
}
