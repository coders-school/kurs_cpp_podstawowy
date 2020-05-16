#pragma once

int fibonacci_iterative(int sequence) {
    
    int f1, f2, f;

    if( sequence == 0) {
        return 0;
    }

    if( sequence == 1) {
        return 1;
    }
    
    f1 = 0;
    f2 = 1;
    for (size_t i = 2; i <= sequence; i++) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    
    return f;
}

int fibonacci_recursive(int sequence) {

    if( sequence == 0) {
        return 0;
    }

    if( sequence == 1) {
        return 1;
    }

    return fibonacci_recursive( sequence - 1 ) + fibonacci_recursive( sequence - 2 );
}
