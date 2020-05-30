#pragma once

int fibonacci_iterative(int sequence) {
    int fCurrent = 1, f1 = 1, f2 = 1;
    
    if (sequence == 0)
      return 0;
    
    for (auto iter = 3 ; iter <= sequence ; iter++) {
      fCurrent = f1 + f2;
      f1       = f2;
      f2       = fCurrent;
    }
    
    return fCurrent;
}

int fibonacci_recursive(int sequence) {
    if(sequence<0)
        return -1;
    else if (sequence<=1)
        return sequence;
        
    return fibonacci_recursive(sequence-1)+fibonacci_recursive(sequence-2);
}
