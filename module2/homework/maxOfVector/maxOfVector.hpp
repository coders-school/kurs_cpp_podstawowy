#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {

int actual_max = vec.at(0);
	for(const auto& element:vec)
	{
		if(actual_max < element)
		{	
			actual_max = element;
		}
	}	

return actual_max;
}
