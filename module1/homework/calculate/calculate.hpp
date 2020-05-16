#pragma once
#include <string>
#include <map>

std::string calculate(const std::string& command, int first, int second) {
    // TODO: Implement your solution here and return proper value
    
int option = 0;
std::map<std::string, int> options { {"add", 1}, {"subtract", 2}, {"multiply", 3}, {"divide", 4}  };

for(auto str : options)
    if(command == str.first)
        option = str.second;

switch(option){

    case 1:
    return std::to_string(first + second);

    case 2:
    return std::to_string(first - second);

    case 3:
    return std::to_string(first * second);
    
    case 4:
    if(second == 0){
    	return "Division by 0";
    	}
    else{	
    	return std::to_string(first / second);
    }
  
    default:
    return "Invalid data";
}

}

