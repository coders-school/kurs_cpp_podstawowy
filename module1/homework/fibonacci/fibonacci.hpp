#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    int next , previous, total;
    total = 1;
    previous = 0;
    next = 1;
    if(sequence < 2)
        return sequence;
    for(int i = 2; i <= sequence; i++){ 
        
        next = previous + total;
        previous = total;
        total = next;
        
    }
    return total;    
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    int total = 0;
    return sequence < 2 ? total += sequence : total += fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2); 
}
