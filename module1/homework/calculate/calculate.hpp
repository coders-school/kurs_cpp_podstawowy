#pragma once
#include <string>
#include <stdio.h>



std::string calculate(const std::string& command, int first, int second){
    // TODO: Implement your solution here and return proper value
    if (command == "add")
    {
    return std::to_string(first+second);
    }
    else if (command == "subtract") {
    return std::to_string(first-second);
    }
    else if (command == "multiply") {
    return std::to_string(first*second);
    }
    else if (command == "divide") {

	    if ((first||second)==0){
            return std::string("Division by 0");
                    }
                        else if((first && second)!=0){
            return std::to_string(first/second);
                        }
    }
 else {
 return std::string("Invalid data");
 }
}
