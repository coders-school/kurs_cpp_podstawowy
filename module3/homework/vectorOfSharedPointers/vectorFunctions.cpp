#include "vectorFunctions.hpp"
#include <iostream>
#include <algorithm>

std::vector<std::shared_ptr<int>> generate(int count)
{
	std::vector<std::shared_ptr<int>> vectorToReturn;
	vectorToReturn.reserve(count);

	for (size_t i = 0; i < count; i++) 
	{
		vectorToReturn.push_back(std::make_shared<int>(i));
	}

	return vectorToReturn;
}

void print(const std::vector<std::shared_ptr<int>>& vectorToPrint)
{
	for(auto const& it : vectorToPrint)
	{
		std::cout << *it;
	}
}

void add10(const std::vector<std::shared_ptr<int>> vector)
{
	for(auto& it : vector)
	{
		if(!it)
		{
			continue;
		}

		*it += 10;
	}
}

void sub10(int * const ptr)
{
	if(!ptr)
	{
		return;
	}

	*ptr -= 10;
}

void sub10(const std::vector<std::shared_ptr<int>> vector)
{
	for(auto& it : vector)
	{
		sub10(it.get());
	}
}

