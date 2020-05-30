#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {

    int even_sum = 0;

    for (auto elements : numbers){
        
        if (elements % 2 == 0 ){

            even_sum += elements;
        }
        
    }
    
    return even_sum;
}
