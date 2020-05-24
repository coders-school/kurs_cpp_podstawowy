#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    int result = 0;
      
    if (command == "add"){
        result = first + second;
        return std::to_string(result);
      } 
    else if (command == "multiply"){
        result = first * second;
        return std::to_string(result);
      }
    else if(command == "subtract"){
        result = first - second;
        return std::to_string(result);
      }
    else if(command == "divide"){
        if (second == 0){
        return std::string("Division by Zero");
        }
        result = first / second;
        return std::to_string(result);
      }
    else {
        return "Invalid data";
    }
    return 0;
}
}
