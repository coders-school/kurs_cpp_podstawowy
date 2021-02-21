#include <iostream>
#include <vector>
#include <list>

std::list<int> createSortedList(std::vector<int>& vec){
    std::list<int> lis;
    for (const auto& i : vec){
        lis.push_back(i);
    }
    lis.sort();
    return lis;
}
// add proper include :)

int main() {
    std::vector<int> vec{2, 3, 4, 1, 6, 5, 8, 7, 9, 0};
    auto list = createSortedList(vec);

    for (const auto& el : list)
        std::cout << el << " ";

    return 0;
}
