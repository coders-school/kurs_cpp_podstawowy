#include <iostream>
#include <vector>
#include <list>

// Implement createSortedList
// add proper include :)

std::list<int> createSortedList(const std::vector <int>v)
{
    std::list<int>list;
    for (const auto& el : v)
    {
        list.push_back(el)    /* code */;
    }
    list.sort();
    return list;
    
}
int main() {
    std::vector<int> vec{2, 3, 4, 1, 6, 5, 8, 7, 9, 0};
    auto list = createSortedList(vec);

    for (const auto& el : list)
        std::cout << el << " ";

    return 0;
}
