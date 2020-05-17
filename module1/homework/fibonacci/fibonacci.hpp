#pragma once

int fibonacci_iterative(int sequence) {

    int tab [] = {0,1};

    if (sequence == 0) {

    return 0;

    }

    if (sequence == 1) {

    return 1;

    }

    while (sequence > 1) {

    int temp = tab[1];
    tab[1] = tab[0] + tab[1];
    tab[0] = temp;

    sequence--;

    }

    return tab[1];


}


int fibonacci_recursive(int sequence) {

     if (sequence <= 1) {

     return sequence;

     }

     return fibonacci_recursive(sequence-1) + fibonacci_recursive(sequence-2);
}
