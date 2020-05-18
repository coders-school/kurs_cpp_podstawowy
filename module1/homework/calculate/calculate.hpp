#pragma once
#include <string>

namespace operations 
{
    constexpr auto add = "add";
    constexpr auto sub = "subtract";
    constexpr auto mul = "multiply";
    constexpr auto div = "divide";
    constexpr auto divByZero = "Division by 0";
}

std::string calculate(const std::string& command, int first, int second) {

    std::string res;
    if (!command.compare(operations::add))
        res = std::to_string(first + second);
    else if (!command.compare(operations::sub))
        res = std::to_string(first - second);
    else if (!command.compare(operations::mul))
        res = std::to_string(first * second);
    else if (!command.compare(operations::div))
        {
            if (second == 0)
                res = operations::divByZero;
            else
                res = std::to_string(first / second);
        }
    else
        res = "Invalid data";
    
    return res;

}
