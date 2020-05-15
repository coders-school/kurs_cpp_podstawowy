#pragma once
#include <string>

std::string calculate(const std::string &command, int first, int second)
{
    if (command == "add") {
        std::string result = std::to_string(first + second);
        return result;
    }
    else if (command == "subtract") {
        std::string result = std::to_string(first - second);
        return result; //std::to_string(first - second);
    }
    else if (command == "multiply") {
        std::string result = std::to_string(first * second);
        return result;
    }
    else if (command == "divide") {
        std::string result;
        if (second == 0) {
            result = "Division by 0";
        }
        else {
            result = std::to_string(first / second);
        }
        return result;
    }
    else
    {
        std::string result = "Invalid data";
        return result;
    }
}
