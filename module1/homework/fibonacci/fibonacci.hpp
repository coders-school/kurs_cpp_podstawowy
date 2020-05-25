#pragma once

int fibonacci_iterative(int sequence) {
    int a = 0;
    int b = 1;
    int var = 0;
    if(sequence > 0)
    {
    for(int i = 1; i < sequence; i++)
    {
        var = b;
        b += a;
        a = var;
        

    }
    return b;
    }
    return 0;
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0)
    {
        return 0;
    }
    if(sequence == 1 || sequence == 2)
    {
        return 1;
    }
    return (fibonacci_recursive(sequence-2)+fibonacci_recursive(sequence-1));


    
}
