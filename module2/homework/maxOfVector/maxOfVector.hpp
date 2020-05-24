#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max_vector_value = vec.at(0);
    for(const auto& element : vec){
        if(element > max_vector_value)
            max_vector_value = element;
    }
    return max_vector_value;
}
