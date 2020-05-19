#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    // TODO: Implement your solution here and return proper value
	
	
  std::string answer = "Invalid data";

  if(command == "add") answer = std::to_string(first + second);
  if(command == "subtract") answer = std::to_string(first - second);
  if(command == "multiply") answer = std::to_string(first * second);

  return answer;

}
