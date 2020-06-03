#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <string>


std::vector<std::shared_ptr<int>> generate(int);
void print(const std::vector<std::shared_ptr<int>>&);
void add10(std::vector<std::shared_ptr<int>>&);
void sub10(std::shared_ptr<int>&);
void sub10(std::vector<std::shared_ptr<int>>&);