#pragma once

int fibonacci_iterative(int sequence) {
    if(sequence<0){
        return -1;
    }else if(sequence==0){
        return 0;
    }else if(sequence<3){
        return 1;
    }
    int a=0, b=1;
    for(int i=1; i<sequence; i++){
        b +=a;
        a = b-a;
    }
    return b;
}

int fibonacci_recursive(int sequence) {
    if(sequence<0){
        return -1;
    }else if(sequence == 0){
        return 0;
    }else if(sequence<3){
        return 1;
    }
    return fibonacci_recursive(sequence-2) + fibonacci_recursive(sequence-1);
    return 0;
}