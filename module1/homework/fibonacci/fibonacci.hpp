#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence == 0){
        return 0;
    }
    uint32_t first{0}, second{1};
    for (int i = 1; i < sequence; i++){
        second += first;
        first = second - first;
    }
    return second;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0){
        return 0;
    }
    else if (sequence < 3){
        return 1;
    }
    else{
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    }
}

