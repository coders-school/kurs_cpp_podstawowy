#pragma once

int fibonacci_iterative(int sequence) {  
    int fibonacciSum[sequence + 2];
    fibonacciSum[0] = 0;
    fibonacciSum[1] = 1;
    for (auto it = 2; it <= sequence; it++) {
       fibonacciSum[it] = fibonacciSum[it - 2] + fibonacciSum[it - 1];
    }
    return fibonacciSum[sequence];
}

int fibonacci_recursive(int sequence) {
    // TODO: Your implementation goes here
    return 0;
}
