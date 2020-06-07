#include<memory>
#include<vector>

std::vector<std::shared_ptr<int>> generate(int count);
void add10(const std::vector<std::shared_ptr<int>> vec);
void print(const std::vector<std::shared_ptr<int>> vec);
void sub10(int* const elem);
void sub10(const std::vector<std::shared_ptr<int>> vec); 
