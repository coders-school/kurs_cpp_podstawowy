#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    
    if (command == "add"){
        return std::to_string(first + second);
      } 
    else if (command == "multiply"){
        return std::to_string(first * second);
      }
    else if(command == "subtract"){
        result = first - second;
        return std::to_string(first - second);
      }
    else if(command == "divide"){
        if (second == 0){
        return std::string("Division by Zero");
        }
        return std::to_string(first / second);
      }
  return "Invalid data";
}
