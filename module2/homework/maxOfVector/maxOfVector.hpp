#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    if(vec.size() == 1)return vec[0];
    if(vec.size() == 2){
        if(vec[0]>vec[1])return vec[0];
         return vec[1];
    }
    int max = vec[0];
    for(auto i = 1; i != vec.size();i++){
        if(max<vec[i]){
        max = vec[i];
        }
    }
    return max;

}
