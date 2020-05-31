#include <iostream>
#include "vectorFunctions.hpp"

void add10(const PointersVector& vec)
{
    for (auto i : vec)
        if (i)
            *i += 10;
};
void print(const PointersVector& vec)
{
    for (auto i : vec)
        std::cout << *i << " ";
    std::cout << "\n";
};

void sub10(const PointersVector& vec)
{
    for (auto i : vec)
        sub10(i.get());
};

void sub10(int* ptr)
{
    if (ptr)
        *ptr -= 10;
};

PointersVector generate(int count)
{
    PointersVector vec;
    vec.reserve(count);
    for (int i = 0; i < count; ++i)
        vec.push_back(std::make_shared<int>(i));
    return vec;
};

