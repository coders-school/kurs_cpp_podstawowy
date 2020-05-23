#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec)
{
    int maxValue = *vec.begin();
    for (auto i = vec.begin(); i != vec.end(); ++i) 
    {
        if (maxValue < *i)
        {
            maxValue = *i;
        }
    }
    return maxValue;
}
