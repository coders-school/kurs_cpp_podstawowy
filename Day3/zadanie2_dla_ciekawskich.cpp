#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

std::map<int, std::string> CreateMapFromVecAndList(const std::vector<int>& vec,
                                            const std::list<std::string>& list) {
  std::map<int, std::string> map;
  std::transform(begin(vec), end(vec), begin(list), std::inserter(map, map.begin()),
    [](const auto& first, const auto& second){
      return std::make_pair(first, second);
    });

  return map;
}

int main() {
  std::vector<int> vec {1,2,3,4,5};
  std::list<std::string> list {"One", "Two", "Three", "Four", "Five"};
  auto map = CreateMapFromVecAndList(vec, list);

  for (const auto& pair : map)
    std::cout << pair.first <<  " | " << pair.second << '\n';

  return 0;
}
