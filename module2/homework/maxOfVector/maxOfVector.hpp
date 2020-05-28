#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    // TODO: Implement me :)
	int maxNum = vec[0];

	for (auto it = vec.begin(); it != vec.end(); it++) {

		if (*it > maxNum) {

			maxNum = *it;
		}

	}

	return maxNum;
}
