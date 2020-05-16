#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) 
{
	
   if(command=="add" || command=="subtract" || command=="divide" || command=="multiply"){
   char commandLet = command.at(0);


	switch (commandLet)
	{
	case 'a':
	return std::to_string(first + second);
        break;

	case 'm':
	return std::to_string(first*second);
 	break;

	case 'd':
	if(second==0){
	return "Division by 0";
	break;
	}

	return std::to_string(first/second);	
	break;

	case 's':
	return std::to_string(first-second);
	break;

	default:
	break;
	}

   }
   
	
	 return "Invalid data";
}
