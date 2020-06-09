#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step)
{
    std::vector<int> sequence;
    if(count > 0)
    {
        sequence.reserve(count);
        int sum = step;
        for(int i= 0; i < count; i++)
        {
            sequence.push_back(sum);
            sum += step;
        }
    }
    return sequence;
}
