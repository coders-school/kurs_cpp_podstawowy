#pragma once
#include <vector>

int maxOfVector(const std::vector<int>& vec) {

	int maxNum = vec[0];

	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (*it > maxNum) {
			maxNum = *it;
		}
	}
	return maxNum;
}
