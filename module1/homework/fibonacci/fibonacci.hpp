#pragma once

int fibonacci_iterative(int sequence) {
    int i = 1;
    int a = 1;
    int b = 1;
    int result = 0;
    while(i <= sequence)
    {
        result = a;
        if(i == sequence)
            break;
        i++;
        a = a+b;
        result = b;
        b = a+b;
        i++;
    }
    return result;
}

int fibonacci_recursive(int sequence) {
    if(sequence <= 1)
         return sequence;
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
