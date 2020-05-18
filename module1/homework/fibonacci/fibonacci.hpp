#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence==0) return 0;
    else if (sequence==1||sequence==2) return 1;
    int a=1;
    int b=1;
    int c;
    for (int i=2; i<sequence; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int fibonacci_recursive(int sequence) {
    if (sequence==0) return 0;
    else if (sequence==1||sequence==2) return 1;
    else return fibonacci_recursive (sequence-1)+fibonacci_recursive (sequence-2);
}
