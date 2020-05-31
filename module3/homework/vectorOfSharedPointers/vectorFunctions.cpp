#include "vectorFunctions.hpp"
#include <iostream>

void add10(PointersVector vec)
{
    for (auto i : vec)
        if (i)
            *i += 10;
};
void print(PointersVector vec)
{
    for (auto i : vec)
        std::cout << *i << " ";
    std::cout << "\n";
};

void sub10(PointersVector vec)
{
    for (auto i : vec)
        if (i)
            *i -= 10;
};

void sub10(int* ptr)
{
    if (ptr)
        *ptr -= 10;
};

PointersVector generate(int count)
{
    PointersVector vec;
    for (int i = 0; i < count; ++i)
        vec.push_back(std::make_shared<int>(i));
    return vec;
};
