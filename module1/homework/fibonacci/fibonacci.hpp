#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence < 0) {
        return -1;
    }
    if (sequence == 0) {
        return 0;
    }
    if (sequence == 1) {
        return 1;
    }
    int current = 1, one_before = 1, two_before = 0;
    for (int i = 2; i <= sequence; ++i) {
        current = one_before + two_before;
        two_before = one_before;
        one_before = current;
    }
    return current;
}

int fibonacci_recursive(int sequence) {
    if (sequence < 0) {
        return -1;
    }
    if (sequence == 0) {
        return 0;
    }
    if (sequence == 1) {
        return 1;
    }
    if (sequence >= 2) {
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    }
    
    return 0;
}
