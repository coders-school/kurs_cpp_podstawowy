#pragma once
#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);

void print(const std::vector<std::shared_ptr<int>>& vectorToPrint);

void add10(const std::vector<std::shared_ptr<int>> vector);

void sub10(int * const number);

void sub10(const std::vector<std::shared_ptr<int>> vector);
