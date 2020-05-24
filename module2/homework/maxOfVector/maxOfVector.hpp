#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    if(vec.size() == 0)
	return 0; 
    auto max = vec[0];
    for(const auto& el : vec)
    {
	if(el > max)
	max = el;
    }
    return max;
}
