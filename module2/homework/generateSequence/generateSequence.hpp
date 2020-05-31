#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
    
    std::vector<int> vec;
    if(count > 0)
    {
    vec.resize(count);
    for(size_t i = 0; i < vec.size(); ++i)
    {   if(i == 0)
        {
            vec[i] = step;
        }
        if(i != 0) 
        {
        vec[i] = vec[i-1] + step;
        }   
    }


    return vec;
    }
    return vec;

}
