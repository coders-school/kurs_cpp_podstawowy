#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);

void print(std::vector<std::shared_ptr<int>>);

void add10(std::vector<std::shared_ptr<int>>);

void sub10(int* ptr);

void sub10(std::vector<std::shared_ptr<int>>);