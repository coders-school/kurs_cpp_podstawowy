#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>
// Implement createMap. It should take a vector and list and
// return a map of merge them as keys from the vector and values from the list
std::map<int, std::string> createMap(const std::vector<int>& a, const std::list<std::string>& b )
{
    std::map<int, std::string>mapa;
    if (a.size() != b.size())
    {
        std::cerr<<"vector size not equal";
        return mapa;
    }
    size_t i = 0;
   
   for (const auto& el : b)
   {
      mapa[a[i++]] = el;
   }
   
    return mapa;
}
int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::list<std::string> list{"One", "Two", "Three", "Four", "Five"};
    auto map = createMap(vec, list);

    for (const auto& pair : map)
        std::cout << pair.first << " | " << pair.second << '\n';

    return 0;
}
