#pragma once
#include <string>
#include <map>

using operation = int (*)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int divide(int a, int b) {
    if (b == 0)
        throw std::overflow_error("Division by 0");
    return a / b;
}

int multiply(int a, int b) {
    return a * b;
}

std::string calculate(const std::string& command, int first, int second) {

    std::map<std::string, operation> calculator = { {"add" , add}, 
                                                    {"subtract", subtract}, 
                                                    {"divide", divide}, 
                                                    {"multiply", multiply} };

    auto search = calculator.find(command);

    if (search == calculator.end()) {
        return "Invalid data";
    } else {
        try {
            auto result = search->second(first, second);
            return std::to_string(result);
        } catch (std::overflow_error e) {
            return e.what();
        }    
    }
}
