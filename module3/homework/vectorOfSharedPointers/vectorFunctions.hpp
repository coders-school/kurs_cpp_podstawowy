#include <memory>
#include <vector>

#pragma once

std::vector<std::shared_ptr<int>> generate(int);
void print(const std::vector<std::shared_ptr<int>>&);
void add10(const std::vector<std::shared_ptr<int>>&);
void sub10(int* const);
void sub10(const std::vector<std::shared_ptr<int>>&);
