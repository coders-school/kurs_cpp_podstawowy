#pragma once
#include <string>

std::string calculate(const std::string &command, int first, int second)
{
    // TODO: Implement your solution here and return proper value
    int opcja = 0;
    if (command == "add")
        opcja = 1;
    if (command == "subtract")
        opcja = 2;
    if (command == "multiply")
        opcja = 3;
    if (command == "divide")
        opcja = 4;

    switch (opcja)
    {
    case 1:
        return std::to_string(first + second);
        break;
    case 2:
        return std::to_string(first - second);
        break;
    case 3:
        return std::to_string(first * second);
        break;
    case 4:
        if (second == 0)
        {
           return "Division by 0";
        }
        return std::to_string(first / second);
        break;
    default:
        return "Invalid data";
        break;
    }
    return "Invalid data";
}
