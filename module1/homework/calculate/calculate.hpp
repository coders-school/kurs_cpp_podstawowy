#pragma once
#include <string>
#include <map>

 enum commands {def, add, subtract, multiply, divide};
 std::map<std::string, commands> commandsMap;

std::string calculate(const std::string& command, int first, int second) {

    commandsMap["default"] = def;
    commandsMap["add"] = add;
    commandsMap["subtract"] = subtract;
    commandsMap["multiply"] = multiply;
    commandsMap["divide"] = divide;

    switch(commandsMap[command]) 
    {
        case add:
            return std::to_string(first+second);
        break;

        case subtract:
            return std::to_string(first-second);
        break;

        case multiply:
            return std::to_string(first*second);
        break;

        case divide:
            if (second == 0) {
                return "Division by 0";
            }
            else{
                return std::to_string(first/second);
            }
            
        break;

        default:
            return "Invalid data";

    }

    // return std::to_string(result);
}
