#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int tmp;
    for(auto number : numbers){
        if(number%2 == 0) tmp += number;
    }
    return tmp;
}
