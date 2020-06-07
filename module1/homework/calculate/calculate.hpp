#pragma once
#include <string>

int result;

std::string calculate(const std::string& command, int first, int second) {
    if (command == "multiply") {
        result = first * second;
        std::cout << result;
    }
    else if (command == "add") {
        result = first + second;
        std::cout << result;
    }
    else if (command == "subtract") {
        result = first - second;
        std::cout << result;
    }
    else if (command == "divide") {
        if (command==0){
            std::cout << "Division by 0";
        }
        result = first / second;
        std::cout << result;
    }
    else {
        std::cout << "Invalid data";
    }
    return "";
}
