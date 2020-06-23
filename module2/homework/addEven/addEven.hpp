#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {

    int result = {};

    for(std::size_t i = 0, elements = numbers.size(); i != elements; ++i)
    {
        if(numbers[i] % 2 == 0)
        {
          result += numbers[i];
        }
    }

    return result;
}
