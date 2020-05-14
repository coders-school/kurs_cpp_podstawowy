#pragma once
#include <string>
#include <sstream>

std::string calculate(const std::string& command, int first, int second)
{
    std::stringstream sstr;
    if (command == "add")
    {
        sstr << first + second;
    }
    else if (command == "subtract")
    {
        sstr << first - second;
    }
    else if (command == "multiply")
    {
        sstr << first * second;
    }
    else if (command == "divide")
    {
        if (second == 0)
        {
            sstr << "Division by 0";
        }
        else
        {
            sstr << first / second;
        }
    }
    else
    {
        sstr << "Invalid data";
    }

    return sstr.str();
}
