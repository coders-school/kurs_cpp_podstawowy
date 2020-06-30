#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int retValue{};
    for(const auto& element : numbers) {
        if(element%2 == 0) {
            retValue += element;
        }
    }
    return retValue;
}
