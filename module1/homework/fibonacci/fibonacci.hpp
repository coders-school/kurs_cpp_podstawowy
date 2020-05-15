#pragma once
#include <vector>
int fibonacci_iterative(int sequence) {
    std::vector<int> fibbo{0,1};
    for(int i = 2 ; i < sequence + 1 ; ++i)
    {
        fibbo.push_back(fibbo[i-1] + fibbo[i-2]);
    }
    return fibbo[sequence];
}

int fibonacci_recursive(int sequence) {
    if(sequence == 0){
        return 0;
    }else if(sequence == 1){
        return 1;
    }
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}  
