#pragma once
#include <string>
#include <cctype>
#include <algorithm>

std::string stringToLower(std::string command);

std::string calculate(const std::string& command, int first, int second) {
    if (stringToLower(command) == "add") {
        return std::to_string(first + second);
    }
    else if (stringToLower(command) == "subtract") {
        return std::to_string(first - second);
    }
    else if (stringToLower(command) == "multiply") {
        return std::to_string(first * second);
    }
    else if (stringToLower(command) == "divide") {
        if (second == 0) {
            return "Division by 0";
        }
        return std::to_string(first / second);
    }
    return "Invalid data";
}

std::string stringToLower(std::string command)
{
    //https://en.cppreference.com/w/cpp/string/byte/tolower
    std::transform(command.begin(), command.end(), command.begin(),
                   [](unsigned char c){ return std::tolower(c); }
                  );
    return command;
}
