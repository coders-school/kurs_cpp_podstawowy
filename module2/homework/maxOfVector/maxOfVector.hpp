#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec)
{
    int maxValue = std::numeric_limits<int>::min();
    for (const auto& value : vec)
    {
        if (value > maxValue)
        {
            maxValue = value;
        }
    }

    return maxValue;
}
