#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    
    int even_sum=0;

    for (const auto & el : numbers)
    {
        if (!(el%2))
        {
            even_sum += el;
        }
    }
    return even_sum;
}
