#pragma once

int fibonacci_iterative(int sequence) {
    
    if(sequence==0)
        return 0;
    if(sequence<=2)
        return 1;

    int res=1, first=0, second=1;

    for(int i = 0;i<sequence-2;i++){

        first=res;
        res +=second;
        second = first;

    }
    return res;
    
}

int fibonacci_recursive(int sequence) {

    if(sequence==0)
        return 0;
    if(sequence<=2)
        return 1;
        
    return fibonacci_recursive(sequence-1) + fibonacci_recursive(sequence-2);    
}
