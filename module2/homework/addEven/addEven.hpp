#pragma once
#include <vector>
#include <algorithm>
#include <numeric>

int addEven(const std::vector<int>& numbers) {
    std::vector<int> result;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(result), [](int i){return i%2==0;} );
    return std::accumulate(result.begin(), result.end(), 0);
}
