#pragma once

int fibonacci_iterative(int sequence) {
    int sum = 0;
    int prev_sum = 0;
    int prev_prev_sum = 0;
    for(int i = 0; i <= sequence; i++)
    {
        if( i == 1)
        {
            prev_prev_sum = 0;
            prev_sum = 1;
            sum = prev_sum;
        }
        else
        {
            sum = prev_sum + prev_prev_sum;
            prev_prev_sum = prev_sum;
            prev_sum = sum;
        }
    }
    return sum;
}

int fibonacci_recursive(int sequence) {
    if(sequence <= 1) return sequence;
    else return (fibonacci_recursive(sequence-1) + fibonacci_recursive(sequence-2));
}
