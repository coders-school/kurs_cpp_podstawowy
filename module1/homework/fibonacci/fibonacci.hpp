#pragma once

int fibonacci_iterative(int sequence){
    int fibonacci_1 = 0, fibonacci_2 = 1;
    for(int i = 0; i < sequence; i++){
        fibonacci_2 += fibonacci_1;
        fibonacci_1 = fibonacci_2 - fibonacci_1;
    }
    return fibonacci_1;
}

int fibonacci_recursive(int sequence){
    if(sequence == 0){
        return 0;
    }
    else if(sequence == 1){
        return 1;
    }
    else{
        return(fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1));
    }
}



