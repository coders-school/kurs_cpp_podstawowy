#pragma once
#include <vector>
#include <climits>

int maxOfVector(const std::vector<int>& vec) {
    int max = INT_MIN;
    for(const auto & el:vec)
	    if (el > max)
		    max = el;
    return max;
}
