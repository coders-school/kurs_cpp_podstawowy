#pragma once
#include <iostream>

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    int beforePrevious = 0; 
    int previous = 1; 
    int temporarySumResult = 0;

    if(sequence == 0){
		return 0;
    }
   
    for (int i = 0; i < sequence; i++) {
      temporarySumResult = beforePrevious + previous;
      beforePrevious = previous;
      previous = temporarySumResult;
   }
   return beforePrevious;
}

int fibonacci_recursive(int sequence) {

    if(sequence == 0){
		return 0;
    }
    if(sequence < 3){
		return 1;
    }
	return fibonacci_recursive(sequence-2)+fibonacci_recursive(sequence-1);
}
