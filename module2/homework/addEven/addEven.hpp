#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int counter{};
    for(auto el : numbers){
        if(el % 2 == 0)
            counter += el;
    }
    return counter;
}
