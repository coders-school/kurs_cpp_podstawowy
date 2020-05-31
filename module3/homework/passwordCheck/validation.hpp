#include <string>

enum class ErrorCode 
{
	Ok,
	PasswordNeedsAtLeastNineCharacters,
	PasswordNeedsAtLeastOneNumber,
	PasswordNeedsAtLeastOneSpecialCharacter,
	PasswordNeedsAtLeastOneUppercaseLetter,
	PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode errorCode);

bool doesPasswordsMatch(std::string password, std::string confirmedPassword);

ErrorCode checkPasswordRules(std::string password);

ErrorCode checkPassword(std::string password, std::string confirmedPassword);