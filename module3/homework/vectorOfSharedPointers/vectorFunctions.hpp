#pragma once

#include <memory>
#include <vector>

std::vector<std::shared_ptr<int>> generate(int count);

void print(const std::vector<std::shared_ptr<int>>& vecOfSharedPtr);

void add10(std::vector<std::shared_ptr<int>>& vecOfSharedPtr);

void sub10(int * const ptrToIntValue);

void sub10(std::vector<std::shared_ptr<int>>& vecOfSharedPtr);
