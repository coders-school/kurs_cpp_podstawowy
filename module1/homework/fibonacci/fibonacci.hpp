#pragma once

int fibonacci_iterative(int sequence) {
    int t0 = 0, t1 = 1, nextTerm = t0+t1;
    if(sequence == 0){
        return 0;
    }
    if(sequence == 1 || sequence == 2){
        return 1;
    }
    for(int i = 1; i<sequence; i++){
        t0 = t1;
        t1 = nextTerm;
        nextTerm = t0 + t1;
    }
    return t1;
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0){
        return 0;
    }
    if(sequence == 1 || sequence == 2){
        return 1;
    }
    return fibonacci_recursive(sequence-1)+fibonacci_recursive(sequence-2);
}
