#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count)
{
    std::vector<std::shared_ptr<int>> vec;
    for (size_t i = 0; i < count; ++i)
    {
        vec.push_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>>& vec)
{
    for (const auto& elem : vec)
    {
        std::cout << *elem << "\n";
    }
}

void add10(std::vector<std::shared_ptr<int>>& vec)
{
    for (auto& elem : vec)
    {
        if (elem != nullptr)
        {
            *elem += 10;
        }
    }
}

void sub10(int* const ptr)
{
    if (ptr != nullptr)
    {
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vec)
{
    for (auto& elem : vec)
    {
        if (elem != nullptr)
        {
            sub10(elem.get());
        }
    }
}
