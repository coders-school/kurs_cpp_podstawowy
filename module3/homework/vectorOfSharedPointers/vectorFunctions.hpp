#pragma once
#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);
int generateRandomNumber(int count);
void print(std::vector<std::shared_ptr<int>> vec);
//void add10(std::vector<std::shared_ptr<int>> vec);
//oid sub10(int* const ptr);
//void sub10(std::vector<std::shared_ptr<int>> vec);
