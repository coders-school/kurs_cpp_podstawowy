#pragma once
#include <memory>
#include <vector>

std::vector<std::shared_ptr<int>> generate(const int count);
void print(const std::vector<std::shared_ptr<int>>& vec);
void add10(const std::vector<std::shared_ptr<int>>& vec);
void sub10(int* const ptr);
void sub10(const std::vector<std::shared_ptr<int>>& vec);
