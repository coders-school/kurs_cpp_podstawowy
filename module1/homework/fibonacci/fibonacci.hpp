#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here

    if ( (sequence == 0) or (sequence == 1)) {
        return sequence;
    }

    int beforePreviousNumber = {}, sequenceNumber = {};
    int previousNumber = 1;
    
    for (size_t i = 2; i <= sequence; i++)
    {
        sequenceNumber = beforePreviousNumber + previousNumber;
        beforePreviousNumber = previousNumber;
        previousNumber = sequenceNumber;
    }

    return sequenceNumber;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    
    return ((sequence == 0) or (sequence == 1) ? sequence : fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
}
