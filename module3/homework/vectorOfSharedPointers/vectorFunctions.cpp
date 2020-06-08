#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count)
{
    std::vector<std::shared_ptr<int>> vec;
    vec.reserve(count);

    for (int i=0; i<count; i++)
          vec.push_back(std::make_shared<int>(i));

    return vec;
}

void print(std::vector<std::shared_ptr<int>>& vec)
{
    for (int i=0; i<vec.size(); i++)
        std::cout <<i<<" : "<< *vec[i] << "\n";
}
void add10(std::vector<std::shared_ptr<int>>& vec)
{
    for (int i=0; i<vec.size(); i++)
        if (vec[i]) 
            *vec[i] += 10;
}

void sub10(int * const pointer)
{
     if (pointer) 
        *pointer -= 10;  
}

void sub10(std::vector<std::shared_ptr<int>>& vec)
{
    for (int i=0; i<vec.size(); i++)
        if(vec[i])
        {
            auto ptr = vec[i];
            sub10(ptr.get());
        }
}