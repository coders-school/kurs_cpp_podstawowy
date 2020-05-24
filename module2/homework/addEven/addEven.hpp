#pragma once
#include <iostream>
#include <vector>
#include <numeric>


bool checkIfEven(int value){
    return value%2 ==0 ;
}

int myBinaryPredicate(int a, int b){
    return checkIfEven(b) ? a+b : a;
    
}


int addEven(const std::vector<int>& numbers) {
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0, myBinaryPredicate);
    return sum;
}

//test
