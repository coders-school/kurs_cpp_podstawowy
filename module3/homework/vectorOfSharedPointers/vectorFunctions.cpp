#include "vectorFunctions.hpp"
#include <iostream>



std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> result;
    result.reserve(count);

    for (int i = 0; i< count; i++) {
        result.push_back(std::make_shared<int>(i));
    }
    return result;
}

void print(const std::vector<std::shared_ptr<int>>& vec)
{
    for (const std::shared_ptr<int> ptr : vec)
    {
        std::cout<<*ptr<<", ";
    }
    std::cout<<'\n';
}

void add10(std::vector<std::shared_ptr<int>>& vec)
{
    for (std::shared_ptr<int> ptr : vec)
    {
        if(ptr != nullptr)
        {
            *ptr += 10;
        }
    }
}

void sub10(int * const ptr)
{
    if(ptr != nullptr)
    {
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vec)
{
    for (std::shared_ptr<int> ptr : vec)
    {
        sub10(ptr.get());
    }
}
