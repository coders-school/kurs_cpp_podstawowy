#include <algorithm>
#include <iostream>
#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {
    std::vector<std::shared_ptr<int>> v(count);
    
    int i = 0;
    for (auto & el : v)
        el = std::make_shared<int>(i++);
    
    return v;
}

void print(const std::vector<std::shared_ptr<int>>& v) {
    std::for_each(begin(v), end(v), [&](const std::shared_ptr<int>& s){ std::cout << *s; });
}

void add10(std::vector<std::shared_ptr<int>>& v) {
    std::for_each(begin(v), end(v), [&](std::shared_ptr<int>& s){
        if (s)
            *s += 10; });
}

void sub10(int* const ptr) {
    if (ptr)
        *ptr -= 10;
}

void sub10(std::vector<std::shared_ptr<int>>& v) {
    std::for_each(begin(v), end(v), [&](std::shared_ptr<int>& s){
        if (s)
            sub10(s.get());
    });
}