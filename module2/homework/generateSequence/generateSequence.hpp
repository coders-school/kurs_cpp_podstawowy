#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step)
{
    if(count > 0)
    {
        std::vector<int> result;
        int value = step;

        for(size_t i = 0; i < count; i++)
        {
            result.push_back(value);
            value += step;
        }
        return result;
    }
    return {};
}
