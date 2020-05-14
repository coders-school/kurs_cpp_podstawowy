#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    if(sequence == 0) return 0;
    if(sequence < 3) return 1;

    int result = 0 ;
    int x = 0;
    int y = 1;
    for(int i = 2; i <= sequence; i++)
    {
        result = x + y;
        x = y;
        y = result;
    }
    return result;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    if(sequence == 0)return 0;
    if(sequence < 3) return 1;

    return fibonacci_recursive(sequence-2) + fibonacci_recursive(sequence-1);
}
