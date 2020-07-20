#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int> > generate(int count)
{
    std::vector<std::shared_ptr<int> > tmpVec;
    for (int i = 0; i < count; i++) {
        tmpVec.emplace_back(std::make_shared<int>(i));
    }
    return tmpVec;
}

void print(const std::vector<std::shared_ptr<int> >& vec)
{
    for (auto& el : vec) {
        std::cout << *el << " ";
    }
    std::cout << "\n";
}

void add10(std::vector<std::shared_ptr<int> >& vec)
{
    for (auto& el : vec) {
        if (el.get()) {
            *el += 10;
        }
    }
}

void sub10(int* const ptr)
{
    if (ptr) {
        *ptr -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int> >& vec)
{
    for (auto& el : vec) {
        sub10(el.get());
    }
}
