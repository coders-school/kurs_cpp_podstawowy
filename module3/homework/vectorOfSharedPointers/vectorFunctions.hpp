#pragma once
#include <vector>
#include <memory>

using PointersVector = std::vector<std::shared_ptr<int>>;

void add10(PointersVector);
void print(PointersVector);
void sub10(PointersVector);
void sub10(int*);
PointersVector generate(int count);
