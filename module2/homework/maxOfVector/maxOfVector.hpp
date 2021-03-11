#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    // for(auto it = vec.begin() + 1 ; it != vec.end(); ++it)
    // {
    //     temp = vec[0];
    //     if (*it > temp)
    //     {
    //         temp = *it;
            
    //     }
    //      std::cout<<"wieksza = "<<temp<<std::endl;
    // }
    int temp = vec[0];
    for(const auto& el : vec)
    {
        if (el > temp)
        {
            temp = el;
        }
    }
    return temp;
}