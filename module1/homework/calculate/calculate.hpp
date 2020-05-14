#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    // TODO: Implement your solution here and return proper value
    int result {};


    if("add" == command)
        result = first + second;
    else if("subtract" == command)
        result = first - second;
    else if("multiply" == command)
        result = first * second;
    else if("divide" == command)
    {
        if(0 == second)
            return "Division by 0";
        result = first / second;
    }
    else
        return "Invalid data";
    

    return std::to_string(result);
}
