#pragma once

int fibonacci_iterative(int sequence) {
    if(sequence == 0 || sequence == 1)
        return sequence;

    int previousPreviousValue, previousValue{0}, currentValue{1};

    for(std::size_t i = 1; i < sequence; ++i) {
        previousPreviousValue = previousValue;
        previousValue = currentValue;
        currentValue = previousPreviousValue + previousValue;
    }
    return currentValue;
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0 || sequence == 1)
        return sequence;

    return (fibonacci_recursive(sequence-2) + fibonacci_recursive(sequence-1));
}
