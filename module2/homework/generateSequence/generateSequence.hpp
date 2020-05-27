#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step)
{
    if (count < 0)
        return {};

    std::vector<int> output(count);

    int cur_step_value = step;
    for (auto & i : output)
    {
        i = cur_step_value;
        cur_step_value += step;
    }

    return output;
}