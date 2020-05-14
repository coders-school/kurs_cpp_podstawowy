#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence < 0) {
        return 0;
    }
    if (sequence < 2) {
        return sequence;
    }

    int prevPrevNumber = 0, prevNumber = 1, currNumber = 0;

    for (auto i = 2; i <= sequence; i++) {
        currNumber = prevPrevNumber + prevNumber;
        prevPrevNumber = prevNumber;
        prevNumber = currNumber;
    }
    return currNumber;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    return 0;
}
