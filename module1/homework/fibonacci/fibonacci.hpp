#pragma once
#include <iostream>

int fibonacci_iterative(int sequence) {

    int first = 1;
    int second = 1;
    int result;

    if (sequence <= 3){
        return 1;
    }
    
    for (int i = 3; i <= sequence; i++) {
        result=first+second;
        second=first;
        first=result;
    }
    return result;
}

int fibonacci_recursive(int sequence) {

    if(sequence == 0) {
        return 0;
}
    else if (sequence < 3) {
      return 1;
}
 return fibonacci_recursive(sequence-2)+fibonacci_recursive(sequence-1);
}

