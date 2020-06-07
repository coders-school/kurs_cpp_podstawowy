#include <memory>
#include <vector>
#include <iostream>
#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count)
{
    std::vector<std::shared_ptr<int>> result;
    result.reserve(count);

    for (size_t i = 0; i < count; i++)
    {
        result.emplace_back(std::make_shared<int>(i));
    }

    return result;
}

void sub10(int* const elem)
{
    if (elem)
    {
        *elem -= 10;
    }
}

void print(const std::vector<std::shared_ptr<int>> vec)
{
    for(auto el : vec)
    {
        std::cout << *el << std::endl;
    }
}

std::vector<std::shared_ptr<int>> add10(const std::vector<std::shared_ptr<int>> vec)
{
    for(auto elem : vec)
    {
       *elem += 10;     
    }
}

void sub10(const std::vector<std::shared_ptr<int>> vec)
{
    for( auto el : vec)
    {
        sub10(el.get());
    }
}
