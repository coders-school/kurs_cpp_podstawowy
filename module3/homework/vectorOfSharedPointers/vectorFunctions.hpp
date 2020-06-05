#pragma once

#include <iostream>
#include <memory>
#include <vector>

void print(const std::vector<std::shared_ptr<int>>& vec);
void add10(std::vector<std::shared_ptr<int>>& vec);
void sub10(int* const ptr);
void sub10(std::vector<std::shared_ptr<int>>& vec);
std::vector<std::shared_ptr<int>> generate(int count);
