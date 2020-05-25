#pragma once

int fibonacci_iterative(int sequence) {
    int temp=0, first=1, second=1;
    for(int i=1;i<=sequence;i++)
    {
        second = first;
        first = temp;
        temp = first + second;
    }
    return temp;
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0)
        return 0;
    if(sequence<3){
        return 1;
    }else{
        return fibonacci_recursive(sequence - 2) +
            fibonacci_recursive(sequence - 1);
    }
}
