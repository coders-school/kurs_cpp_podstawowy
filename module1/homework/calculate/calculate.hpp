#pragma once
#include <string>
#include <vector>
#include <algorithm>



std::string calculate(const std::string& command, int first, int second) {
    
    // TODO: Implement your solution here and return proper value
    std::vector <std::string> comm{"add", "subtract", "multiply", "divide"};
    auto res = std::find(std::begin(comm), std::end(comm), command);
    int menu = std::distance(std::begin(comm), res);

    switch(menu)
    {
    case 0:
        return std::to_string(first+second);
    case 1:
        return std::to_string(first-second);
    case 2:
        return std::to_string(first*second);
    case 3:
        if(second==0)
            return "Division by 0";
        return std::to_string(first/second);
    default:
        return "Invalid data";
    }
	
}
