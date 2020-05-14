#pragma once

int fibonacci_iterative(int sequence) {
    if(0 == sequence)
        return 0;
    else if(1 == sequence)
        return 1;
    
    int fibNumber{0};
    int first{0};
    int second{1};

    for(int i = 2; i <= sequence; i++)
    {
        fibNumber = first + second;
        first = second;
        second = fibNumber;
    }

    return fibNumber;
}

int fibonacci_recursive(int sequence) {
    if(0 == sequence)
        return 0;
    else if(2 >= sequence)
        return 1;


    return fibonacci_recursive(sequence-2) + fibonacci_recursive(sequence-1);
}
