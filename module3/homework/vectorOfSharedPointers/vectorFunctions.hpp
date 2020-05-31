#pragma once

std::vector<std::shared_ptr<int>> generate(int count);
void print(std::vector<std::shared_ptr<int>> numbers);
void add10(std::vector<std::shared_ptr<int>> numbers);
void sub10(int* const number);
void sub10(std::vector<std::shared_ptr<int>> numbers);