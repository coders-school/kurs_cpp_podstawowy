

#include <vector>
#include <algorithm>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count) ;
void print(std::vector<std::shared_ptr<int>>vec);
void add10(std::vector<std::shared_ptr<int>>vec);
void sub10(int* const); //
void sub10(std::vector<std::shared_ptr<int>>); 