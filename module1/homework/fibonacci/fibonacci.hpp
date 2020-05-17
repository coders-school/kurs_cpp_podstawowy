#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence < 0) {
        throw std::invalid_argument("Fibonacci sequence index cannot be negative.");
    } else if (sequence <= 1) {
        return sequence;
    }

    int previousValue{1}, 
        currentValue{1};

    for (int i = 2; i < sequence; ++i) {
        int tempValue = currentValue;
        currentValue += previousValue;
        previousValue = tempValue;
    }

    return currentValue;
}

int fibonacci_recursive(int sequence) {
    if (sequence < 0) {
        throw std::invalid_argument("Fibonacci sequence index cannot be negative.");
    } else if (sequence <= 1) {
        return sequence;
    }

    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
