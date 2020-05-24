#pragma once

int fibonacci_iterative(int sequence) {
    
    if( (sequence == 0) || (sequence == 1) ){
    return sequence;
    }
    
    int a = 1; 
    int b = 1;
    
    for(int i = 0; i < sequence - 2; i++) {
        std::swap(a, b);
        b += a;
    }
    return b;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0 || sequence == 1){
        return sequence;
        }
    return (fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2));
}
