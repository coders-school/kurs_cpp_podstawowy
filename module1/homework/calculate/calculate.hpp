#pragma once
#include <string>
#include <map>

std::string calculate(const std::string& command, int first, int second) {
    // TODO: Implement your solution here and return proper value
    
int total = 0;
int option = 0;
std::string result;
std::map<std::string, int> options { {"add", 1}, {"subtract", 2}, {"multiply", 3}, {"divide", 4}  };

for(auto str : options)
    if(command == str.first)
        option = str.second;

switch(option){

    case 1:
    total = first + second;
    result = std::to_string(total);
    break;

    case 2:
    total = first - second;
    result = std::to_string(total);
    break;

    case 3:
    total = first * second;
    result = std::to_string(total);
    break;

    case 4:
    if(second == 0){
    	result = "Division by 0";
    	}
    else{	
    	total = first / second;
    	result = std::to_string(total);
    }
    break;

    default:
    result =  "Invalid data";
    break;
}

return result;
}

