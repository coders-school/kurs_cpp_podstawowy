#pragma once

int fibonacci_iterative(int sequence) {
    
    if(sequence < 2) {
        return sequence;
    }

    int fibi_past = 0;
    int fibi_present = 0;
    int fibi_future = 1;

    for (int i = 0; i < sequence; i++) {
        fibi_present=fibi_past+fibi_future;
        fibi_past=fibi_future;
        fibi_future=fibi_present;
    }
    
    return fibi_past;
}

int fibonacci_recursive(int sequence) {
    if ((sequence == 0) || (sequence == 1)) {
        return sequence;
    } else {
        return fibonacci_recursive(sequence-2) + fibonacci_recursive(sequence-1);
    }
    return 0;
}
