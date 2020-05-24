#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
   
    if (count <=0 )
        return {};

    std::vector<int> tmpVec;
    tmpVec.reserve(count);
    int initialValue= 0;

    for (size_t i=0; i<count; i++)
    {
        tmpVec.push_back(initialValue+=step);
    }
    
    return tmpVec;
}
