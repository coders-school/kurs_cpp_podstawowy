#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    // TODO: Your implementation goes here
    // Below return is only to make this function compile now
    int sum {};

    for(const auto& element : numbers){
        if(!(element % 2)){
            sum += element;
        }
    }
    return sum;
}
