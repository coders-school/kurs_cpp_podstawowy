#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
std::string result{};    
    if(command == "add")
         result = std::to_string(first+second);
    if(command == "subtract")
        result = std::to_string(first-second);

    return result;
}
