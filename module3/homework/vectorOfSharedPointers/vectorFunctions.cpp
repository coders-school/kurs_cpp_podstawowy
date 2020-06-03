#include "vectorFunctions.hpp"

#include <algorithm>
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> v;
    v.reserve(count);
    
    for (size_t i = 0; i < count; ++i)
        v.emplace_back(std::make_shared<int>(i));
    
    return v;
}

void print(const std::vector<std::shared_ptr<int>>& v) {
    std::for_each(begin(v), end(v), [&](const std::shared_ptr<int>& s){ std::cout << *s; });
}

void add10(const std::vector<std::shared_ptr<int>>& v) {
    std::for_each(begin(v), end(v), [&](std::shared_ptr<int>& s){
        if (s)
            *s += 10; });
}

void sub10(int* const ptr) {
    if (ptr)
        *ptr -= 10;
}

void sub10(const std::vector<std::shared_ptr<int>>& v) {
    std::for_each(begin(v), end(v), [&](std::shared_ptr<int>& s){
        if (s)
            sub10(s.get());
    });
}
