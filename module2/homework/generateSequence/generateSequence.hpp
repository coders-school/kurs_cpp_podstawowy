#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    std::vector<int> myVector{};

    if(count <= 0){
        return myVector;
    }

    int currentValue {};
    for(auto i{ 0 }; i < count; ++i){
        myVector.push_back(currentValue += step);
    }

    return myVector;
}
