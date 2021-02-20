#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
	std::vector<int>sequence{};
	int element = 0;
	while(count > 0){
		element += step;
		sequence.push_back(element);
		count--;
	}
    return sequence;
}
