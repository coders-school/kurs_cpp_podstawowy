#ifndef VECTOR_FUNCTIONS_HPP
#define VECTOR_FUNCTIONS_HPP

#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);

void print(const std::vector<std::shared_ptr<int>>& vec);

void add10(std::vector<std::shared_ptr<int>>& vec);

void sub10(int * const ptr);

void sub10(std::vector<std::shared_ptr<int>>& vec);

#endif

