#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    
    if(count <= 0 ){
        return{};
    }

    std::vector<int> result;
    result.reserve(count);
    for (auto i = 1; i <= count; i++)
    {
        result.push_back(step * i);
    }
    
    //while (count <= step) {
//
  //      result.push_back(step);
    //    count += step;
//    }
    
    return {result};
}
