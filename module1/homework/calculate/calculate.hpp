#pragma once
#include <string>
#include <map>

 using pCalculate_fun = std::string (*)(const int& ,const int& );

std::string Add(const int& first,const int& second){
    return  std::to_string((long)(first + second));
}
std::string Subtract(const int& first,const int& second){
    return  std::to_string(first - second);
}
std::string Multiply(const int& first,const int& second){
    return  std::to_string((long)(first * second));
}
std::string Divide(const int& first,const int& second){
    if(second==0)
        return "Division by 0";

    return  std::to_string(first / second);
}
    const std::map<std::string, pCalculate_fun> Map_Command {
        {"add", Add },
        {"subtract", Subtract },
        {"multiply",Multiply},
        {"divide",Divide}
    };
std::string calculate(const std::string& command, int first, int second) {
if ( Map_Command.find(command) == Map_Command.end() ) {
  return "Invalid data";
} else {
  return Map_Command.at(command)(first,second);
}
}
