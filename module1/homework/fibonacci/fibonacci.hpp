#pragma once

int fibonacci_iterative(int sequence){
    int fibonacci[sequence];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i = 2; i <= sequence; i++){
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    return fibonacci[sequence];
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0){
        return 0;
    }
    else if(sequence < 3){
        return 1;
    }
    else{
        return(fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
    }
}



