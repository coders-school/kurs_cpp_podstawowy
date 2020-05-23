#pragma once

int fibonacci_iterative(int sequence) {
    int a = 0, b = 1, c = 1;
    for(int i=1;i<=sequence;i++)
    {
        c = b;
        b = a;
        a = b + c;
    }
    return a;
}


int fibonacci_recursive(int sequence) {
  
    }
