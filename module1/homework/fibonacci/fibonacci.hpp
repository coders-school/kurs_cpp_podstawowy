#pragma once

int fibonacci_iterative(int sequence) {
    if(sequence == 0) {
        return 0;
    }
    int tab[sequence];
    tab[0] = 1;
    tab[1] = 1;
    for (int i = 2; i < sequence; i++) {
        tab[i] = tab[i-1] + tab[i-2];
    }
    return tab[sequence-1];
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0) {
        return 0;
    }
    if(sequence == 1) {
        return 1;
    }
    if(sequence == 2) {
        return 1;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
