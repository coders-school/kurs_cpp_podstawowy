#pragma once

//here we should only use unsigned int
int fibonacci_iterative(int sequence) 
{
    if (sequence == 0) 
    {
        return 0;
    }

    int result = 0;
    int numb1 = 1;
    int numb2 = 1;

    if (sequence <= 2) 
    {
        return numb1;
    }

    for (int i = 3; i <= sequence; i++) 
    {
        result = numb1 + numb2;
        numb1 = numb2;
        numb2 = result;
    }
    
    return result;
}

//here we should only use unsigned int
int fibonacci_recursive(int sequence) 
{    
    if (sequence <= 1) 
    {
        return sequence;
    }

    return fibonacci_recursive(n - 2) + fibonacci_recursive(n - 1);
}
