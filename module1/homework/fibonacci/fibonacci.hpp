#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    
     if(sequence==0) {return 0;}
      long long first = 0, second = 1;
     for(int i=0;i<sequence;i++)
     {            
            second += first; 
            first = second-first; 
     }

    return first;
}

int fibonacci_recursive(int sequence) {
    if(sequence==0) {return 0;}
    // TODO: Your implementation goes here
    if (sequence ==1) return 1;
    
    return fibonacci_recursive(sequence-1)+fibonacci_recursive(sequence-2);
}
