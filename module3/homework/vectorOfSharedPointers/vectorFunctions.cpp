#include <memory>
#include <vector>

#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count)
{
    std::vector<std::shared_ptr<int>> result;
    result.reserve(count);

    for (size_t i = 0; i < count; i++)
    {
        result.emplace_back(std::make_shared<int>(i));
    }

    return result;
}

void sub10(int* const elem)
{
    if (elem)
    {
        *elem -= 10;
    }
}