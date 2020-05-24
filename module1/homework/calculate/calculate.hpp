#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    std::string result("0");
	if(command == "add" || command == "subtract" || command == "multiply" || command == "divide")
	{
    char operation = command[0];
	
	switch (operation) 
	{
	case 'a':
		result = std::to_string(first + second);
		return result;
		break;
	case 's':
		result = std::to_string(first - second);
		return result;
		break;
	case 'm':
		result = std::to_string(first * second);
		return result;
		break;
	case 'd':
		if (second != 0)
		{
			result = std::to_string(first / second);
			return result;
		}
		else
		{
			
			return "Division by 0"; 
		}
		break;
	
	}
	
}

return "Invalid data";
}


