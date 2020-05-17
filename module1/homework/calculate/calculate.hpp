#pragma once
#include <string>
#include <algorithm>

std::string add(int first, int second) {
    return std::to_string(first + second);
}

std::string subtract(int first, int second) {
    return std::to_string(first - second);
}

std::string multiply(int first, int second) {
    return std::to_string(first * second);
}

std::string divide(int first, int second) {
    return std::to_string(first / second);
}

std::string calculate(const std::string& command, int first, int second) {
    if (command == "add") {
        return add(first, second);
    }

    if (command == "subtract") {
        return subtract(first, second);
    }

    if (command == "multiply") {
        return multiply(first, second);
    }

    if (command == "divide") {
        return divide(first, second);
    }

    return "Invalid data";
}
