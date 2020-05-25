#pragma once

int fibonacci_iterative(int sequence){
    int firstNumber = 0;
    if(sequence == 0){
        return firstNumber;
    }
    int secondNumber = 1;
    if(sequence == 1){
        return secondNumber;
    }
    for(int i = 2; i <= sequence; i++){
        int tmp = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = tmp;
    }
    return secondNumber;
}

int fibonacci_recursive(int sequence){
    if(sequence == 0){
        return 0;
    }
    if(sequence == 1){
        return 1;
    }
    return fibonacci_recursive(sequence -2) + 
        fibonacci_recursive(sequence -1);
}
