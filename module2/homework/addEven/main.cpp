#include <iostream>
#include <vector>
#include "addEven.hpp"

int addEven( std::vector<int>& vec )
{
    int sum= 0;
    for(const auto& el : vec){
        if( el%2 == 0)
            sum+= el;
    }
    return sum;
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << addEven(vec) << "\n";

    return 0;
}
