#pragma once

int fibonacci_iterative(int sequence) {
    if(sequence < 2) {
        return sequence;
    }
    int first = 0;
    int second = 1;
    int third = 1;
    for(int i = 2; i < sequence; ++i) {
        first = second;
        second = third;
        third = first + second;
    }
    return third;
}

int fibonacci_recursive(int sequence) {
    if(sequence < 2) {
        return sequence;
    }
    return fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1);
}
