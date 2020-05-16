#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    if ("add" == command){
        return std::to_string(first + second);
    }
    else if ("subtract" == command){
        return std::to_string(first - second);
    }

    return "";
}
