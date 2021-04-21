#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    if(numbers.empty()){
        std::cerr << "Vector is empty!";
        return 0;
    }
    int sum{};
    for(const auto& number : numbers){
        if(!(number % 2)){
            sum += number;
        }
    }
    return sum;
}
