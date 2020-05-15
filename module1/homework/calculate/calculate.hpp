#pragma once
#include <string>

enum State {add, subtract, multipty, divide, invalid};

State String2State(const std::string& command)
{
    if (command == "add") return add;
    if (command == "subtract") return subtract;
    if (command == "multiply") return multipty;
    if (command == "divide") return divide;
    return invalid;
}

std::string calculate(const std::string& command, int first, int second)
{
    // TODO: Implement your solution here and return proper value
    switch (String2State(command))
    {
        case add:
            return std::to_string(first + second);
        case subtract:
            return std::to_string(first - second);
        case multipty:
            return std::to_string(first * second);
        case divide:
            if (second == 0)
            {
                return "Division by 0";
            }
            return std::to_string(first / second);
        default:
            return "Invalid data";
    }
    return "Invalid data_";
}
