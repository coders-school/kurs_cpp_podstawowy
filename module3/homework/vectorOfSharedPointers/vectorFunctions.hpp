#include <memory>
#include <iostream>
#include <vector>
std::vector<std::shared_ptr<int>> generate(const int count);
void print(const std::vector<std::shared_ptr<int>>& vec);
void add10(std::vector<std::shared_ptr<int>>& vec);
void sub10(int *const number);
void sub10(std::vector<std::shared_ptr<int>>& vec);

