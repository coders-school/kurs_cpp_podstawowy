#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec)
{
    int max = vec.front();

    for (size_t i = 1; i < vec.size(); i++)
    {
        vec[i] > max ? max = vec[i] : 0;
    }
    return max;
}
