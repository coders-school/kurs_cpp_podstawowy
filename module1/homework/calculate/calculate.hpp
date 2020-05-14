#pragma once
#include <string>
#include <algorithm>
#include <cstdlib>

const std::string commands[5] = {"add", "subtract", "multiply", "divide", "quit"};

std::string calculate(const std::string& command, int first, int second) {
    auto x = std::find(begin(commands), end(commands), command);
    if(*x == command){
        auto first_letter = command[0];
        switch (first_letter)
        {
        case 'a':
            return std::to_string(first + second); 
            break;
        case 's':
            return std::to_string(first - second); 
            break;
        case 'm':
            return std::to_string(first * second); 
            break;
        case 'd':
            if(second == 0)return "Divide by 0";
            return std::to_string(first / second); 
            break;
        case 'q':
            exit(0);
        default:
            break;
        }
    }    
    return "Invalid data";
}
