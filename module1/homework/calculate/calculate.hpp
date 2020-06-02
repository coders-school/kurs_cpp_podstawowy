#pragma once
#include <iostream>
#include <string>

std::string calculate(const std::string& command, int first, int second) {

  std::string result = "Invalid data";

  if(command == "add") {
    result = std::to_string(first + second);
  }
  if(command == "subtract") {
    result = std::to_string(first - second);
  }
  if(command == "multiply") {
    result = std::to_string(first * second);
  }
  if(command == "divide") {
    result = "Division by 0";
    if(second != 0) {
      result = std::to_string(first / second);    
    }   
  }
return result;
}