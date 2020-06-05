#pragma once

#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<int>& vec);
void add10(std::vector<int>& vec);
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(const int count);
void print(const std::vector<std::shared_ptr<int>>& vec);
void add10(std::vector<std::shared_ptr<int>>& vec);
void sub10(std::vector<std::shared_ptr<int>>& vec);
void sub10(int* const el);