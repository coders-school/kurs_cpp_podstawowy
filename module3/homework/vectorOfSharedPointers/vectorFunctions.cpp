#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count)
{
	std::vector<std::shared_ptr<int>> vectorToReturn;

	for (size_t i = 0; i < count; i++) 
	{
		vectorToReturn.push_back(std::make_shared<int>(i));
	}

	return vectorToReturn;
}
