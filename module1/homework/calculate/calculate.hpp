#pragma once
#include <string>
#include <map>

// using calculate_fun = std::string (*)(int,int);

typedef std::string (*pCalculate_fun)(const int& ,const int& );
        enum Enum_Commmand{
add, subtract, multiply, divide
};

std::string Add(const int& first,const int& second){
    return  std::to_string((long)(first + second));
}
std::string Subtract(const int& first,const int& second){
    return  std::to_string(first - second);
}
std::string Multiply(const int& first,const int& second){
    return  std::to_string((long)(first * second));
}
    const std::map<std::string, pCalculate_fun> Map_Command {
        { "add", Add },
         { "subtract", Subtract },
        {"multiply",Multiply},
        // {"divide",divide}
    };
    

std::string calculate(const std::string& command, int first, int second) {

    // TODO: Implement your solution here and return proper value
if ( Map_Command.find(command) == Map_Command.end() ) {
  return "Invalid data";
} else {
  return Map_Command.at(command)(first,second);
}

}
