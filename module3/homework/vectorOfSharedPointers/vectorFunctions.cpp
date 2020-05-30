#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count)
{
    std::vector<std::shared_ptr<int>> vec;
    for (int i = 0; i < count; i++)
    {
        vec.push_back(std::make_shared<int>(i));
    }
    return vec;
}

void print(std::vector<std::shared_ptr<int>> vec) 
{
    for (const auto& el : vec)
    {
        std::cout<<*el<<'\n';
    }
}
void add10(std::vector<std::shared_ptr<int>> vec)
{
    for (const auto& el : vec)
    {
        if (el != nullptr)
        {
            *el += 10;
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
void sub10(std::vector<std::shared_ptr<int>> vec)
{
    for (const auto& el : vec)
    {
        if (el !=  nullptr)
        {
            *el -= 10;
        }
    }
}