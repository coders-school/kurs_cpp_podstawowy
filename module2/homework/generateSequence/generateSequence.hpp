#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) 
{
    std::vector<int> sequenceResult;

    if (count <= 0)
    {
        return sequenceResult;
    }
    else
    {
        for (size_t i = 0; i < count; i++)
        {
            sequenceResult.push_back(step * (i+1));
        }
        return sequenceResult;
    }
}
