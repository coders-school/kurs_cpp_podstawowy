#pragma once
#include <string>
#include <map>
#include <functional>

std::string calculate(const std::string &command, int first, int second) {
  
  std::map<std::string, std::function<int(int,int)>> mapOperator;
  mapOperator["add"] = std::plus<int>();
  mapOperator["subtract"] = std::minus<int>();
  mapOperator["divide"] = std::divides<int>();
  mapOperator["multiply"] = std::multiplies<int>();

  if (mapOperator.count(command) == 0) {
    return "Invalid data";
  }
  if (command == "divide" and !(second)) {
    return "Division by 0";
  }
  return std::to_string(mapOperator[command](first, second));
}
