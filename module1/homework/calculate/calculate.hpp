#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) 
{
    std::string result;
	
   if(command=="add" || command=="subtract" || command=="divide" || command=="multiply"){
   char commandLet = command.at(0);


	switch (commandLet)
	{
	case 'a':
	result = std::to_string(first + second);
        break;

	case 'm':
	result = std::to_string(first*second);
 	break;

	case 'd':
	if(second==0){
	result = "Division by 0";
	break;
	}

	result = std::to_string(first/second);	
	break;

	case 's':
	result = std::to_string(first-second);
	break;

	default:
	break;
	}

	
	return result;
   }
   
   else { 
	
	 return "Invalid data";
   }
}
