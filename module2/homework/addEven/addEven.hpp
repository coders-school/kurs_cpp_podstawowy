#pragma once
#include <vector>
#include <iostream>
int addEven(const std::vector<int> &numbers) {
    int tmp = 0;
    for(const auto number : numbers){
        if(number%2 == 0) tmp += number;
    }
    return tmp;
}
