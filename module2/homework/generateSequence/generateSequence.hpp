#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {

std::vector <int> generatorResult;
if(count>0){
	for(int i = 0, j=step; i<count; i++, j+=step)
	{
		generatorResult.push_back(j);
	}
}

return generatorResult;
}
