#include <iostream>
#include <list>
#include <vector>

// Implement createSortedList
// add proper include :)
std::list<int> createSortedList(const std::vector<int>& vector) {
    std::list<int> result;

    for (const auto& el : vector) {
        result.push_back(el);
    }

    result.sort();

    return result;
}

int main() {
    std::vector<int> vec{2, 3, 4, 1, 6, 5, 8, 7, 9, 0};
    auto list = createSortedList(vec);

    for (const auto& el : list)
        std::cout << el << " ";

    return 0;
}
