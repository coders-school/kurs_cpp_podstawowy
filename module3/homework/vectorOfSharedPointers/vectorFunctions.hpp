#pragma once
#include <vector>
#include <memory>

using VecOfSharedPtr = std::vector<std::shared_ptr<int>>;

void add10(VecOfSharedPtr);
void print(VecOfSharedPtr);
void sub10(VecOfSharedPtr);
void sub10(int*);
VecOfSharedPtr generate(int count);
