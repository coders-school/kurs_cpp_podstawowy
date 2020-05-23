#pragma once

int fibonacci_iterative(int sequence) {
    // TODO: Your implementation goes here
    if(sequence == 0){
        return 0;
    }
    else if(sequence == 1){
        return 1;
    }
    int fibo_n_2{ 0 };
    int fibo_n_1{ 1 };
    int temp_result{ 0 };

    for(auto i{ 2 }; i <= sequence; ++i){
        temp_result = fibo_n_2 + fibo_n_1;
        fibo_n_2 = fibo_n_1;
        fibo_n_1 = temp_result;
    }

    return fibo_n_1;
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    return 0;
}
