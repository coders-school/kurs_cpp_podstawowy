#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    if (sequence < 2)
    {
        return sequence;
    }
    int elementA = 0;
    int elementB = 1;
    int result;
    for (int i = 2; i <= sequence; i++){
        result = elementB + elementA;
        elementA = elementB;
        elementB = result;
    }
    
    return elementB;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    if  (sequence < 2)
    {
        return sequence;
    }
    else {
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    }
    return 0;
}
