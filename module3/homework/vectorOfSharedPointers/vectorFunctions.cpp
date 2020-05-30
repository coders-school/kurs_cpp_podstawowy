#include "vectorFunctions.hpp"

void add10(VecOfSharedPtr vec){};
void print(VecOfSharedPtr vec){};
void sub10(VecOfSharedPtr vec){};
void sub10(int* ptr){};
VecOfSharedPtr generate(int count)
{
    VecOfSharedPtr vec;
    for (int i = 0; i < count; i++)
        vec.push_back(std::make_shared<int>(i));
    return vec;
};
