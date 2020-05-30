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

bool doesPasswordsMatch(std::string password1, std::string password2)
{
	if (password1.size() == password2.size())
	{
		for (int i = 0; i < password1.size(); i++)
		{
			if (password1[i] != password2[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

ErrorCode checkPasswordRules(std::string password)
{
	if (password.size() < 9)
	{
		return ErrorCode::PasswordNeedsAtLeastNineCharacters;
	}
	else if (any_of(password.begin(), password.end(), isdigit) == false)
	{	
		return ErrorCode::PasswordNeedsAtLeastOneNumber;
	}
	else if (any_of(password.begin(), password.end(), [](int i) {return ((i >= 33 && i <= 47) || (i >= 58 && i <= 64) || (i >= 91 && i <= 96) || (i >= 123 && i <= 125)); }) == false)
	{
		return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
	}
	else if (any_of(password.begin(), password.end(), isupper) == false)
	{
		return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
	}
	else
	{
		return ErrorCode::Ok;
	}
}

ErrorCode checkPassword(std::string password1, std::string password2)
{
	if (doesPasswordsMatch(password1, password2))
	{
		return checkPasswordRules(password1);
	}
	return ErrorCode::PasswordsDoesNotMatch;
}