#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    int max;
       max = vec.front();
       for (int i = 1; i < vec.size(); i++){
           if (vec[i] > vec[i - 1]){
               max = vec[i];
       } else
           i ++;
     }
    return max;
}
