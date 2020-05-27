#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int suma=0;
    for (const auto &it : numbers){
        if (it % 2==0) {suma+=it;}
    }
    return suma;
}
