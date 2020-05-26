#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {

    int max = vec.front();
    
    for (auto it = vec.begin()+1; it != vec.end(); it++)
    {
        if (*it > max)
        {
            max = *it;
        }
    }
    return max;
}
