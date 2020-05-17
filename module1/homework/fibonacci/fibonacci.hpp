#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence <= 1) {
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
    // TODO: Your implementation goes here
    return 0;
}
