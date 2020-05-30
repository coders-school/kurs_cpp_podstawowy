#include "validation.hpp"


std::string getErrorMessage(ErrorCode err)
{
	switch (static_cast<int>(err))
	{
		case 0:
			return "Well Done";
		case 1:
			return "Password needs at least nine characters";
		case 2:
			return "Password needs at least one number";
		case 3:
			return "Passwrod needs at least one special character";
		case 4:
			return "Password needs at least one Uppercase letter";
		case 5:
			return "Password does not match";
		default:
			return "Error";
	}
	
}