#pragma once
#include <vector>
#include <limits>
#include <set>

int maxOfVector(const std::vector<int>& vec) {
    std::set<int> mySet(vec.begin(), vec.end());
    std::set<int>::iterator it= std::prev(mySet.end());
    return (*it);
}
