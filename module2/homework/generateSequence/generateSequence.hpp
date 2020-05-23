#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) 
{
    std::vector<int> sequence;

    if (count > 0)
    {
        sequence.resize(count);
        int value = step;

        for(int i = 0; i < sequence.size(); i++)
        {
            sequence[i] = value;
            value += step;
        }
    }

    return sequence;
}
