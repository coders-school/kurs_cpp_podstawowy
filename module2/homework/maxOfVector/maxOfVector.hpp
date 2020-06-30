#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int retValue = std::numeric_limits<int>::min();
    for(const auto& element : vec) {
        if(retValue < element) {
            retValue = element;
        }
    }
    return retValue;
}
