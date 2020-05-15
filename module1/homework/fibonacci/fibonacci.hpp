#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    int total[sequence+2];
    total[0] = 0;
    total[1] = 1;

    for(int i = 2; i <= sequence; i++){ 
        total[i] = total[i-1]+total[i-2];
    }
    return total[sequence];    
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    int total = 0;
    return sequence < 2 ? total += sequence : total += fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2); 
}
