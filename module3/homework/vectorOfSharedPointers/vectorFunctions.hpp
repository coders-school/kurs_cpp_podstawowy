#pragma once
#include <vector>
#include <memory>

using PointersVector = std::vector<std::shared_ptr<int>>;

void add10(const PointersVector&);
void print(const PointersVector&);
void sub10(const PointersVector&);
void sub10(int*);
PointersVector generate(int count);

