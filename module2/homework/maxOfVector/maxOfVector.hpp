#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int> &vec)
{
    auto max = vec[0];
    for (const auto &num : vec)
    {
        if (num > max)
        {
            max = num;
        }
    }
    return max;
}
