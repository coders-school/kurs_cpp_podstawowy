#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
int result;
    // double result;
    if (command == "add") {
        result = first + second;
    }
    else if (command == "subtract") {
        result = first - second;
    }
    else if (command == "multiply") {
        result = first * second;
    }
    else if (command == "divide") {
        if (second) {
            result = first / second;
            //result = static_cast<double>(first) / static_cast<double>(second);
        }
        else {
            return "Division by 0";
        }
    }
    else {
        return "Invalid data";
    }
    std::string str = std::to_string(result);
    // remove trailing zeroes in double
    //str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    // remove dot in double
    //str.erase(str.find_last_not_of('.') + 1, std::string::npos );
    return str;
}
