#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    if(vec.empty())
    {
        return 0;
    }

    int maxValue = vec[0];
    
    for(auto elem : vec)
    {
        if(maxValue < elem)
        {
            maxValue = elem;
        }
    }
    return maxValue;
}
