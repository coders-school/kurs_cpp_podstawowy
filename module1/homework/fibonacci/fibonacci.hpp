#pragma once

int fibonacci_iterative(int sequence){
    int Fnext{};
    int F0{};
    int F1 = 1;
    
    if(sequence == 1 || sequence == 0){
        Fnext = sequence;
    }
    else{
        for(int i = 2; i <= sequence; ++i){        
            Fnext = F0 + F1;
            F0 = F1;
            F1 = Fnext;
        }
    }
    return Fnext;
}

int fibonacci_recursive(int sequence) {
    if(sequence == 1 || sequence == 0){
        return sequence;
    }
    else{
        return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
    }   
}
