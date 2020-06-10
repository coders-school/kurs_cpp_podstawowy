#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    
    std::vector<int> result{};
    auto counter {0};
    auto currentElement {0};

    while(count>counter){
        currentElement+=step;
        result.push_back(currentElement);
        counter++;
    }
    return result;
}
