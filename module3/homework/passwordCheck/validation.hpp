#pragma once
#include <string>
#include <map>

enum class ErrorCode 
{
	Ok,
	PasswordNeedsAtLeastNineCharacters,
	PasswordNeedsAtLeastOneNumber,
	PasswordNeedsAtLeastOneSpecialCharacter,
	PasswordNeedsAtLeastOneUppercaseLetter,
	PasswordsDoesNotMatch
};

extern std::map<ErrorCode, const char*> ErrorMap;

std::string getErrorMessage(const ErrorCode errorCode);

bool passwordHasNineCharacters(const std::string& password);

bool passwordHasNumber(const std::string& password);

bool passwordHasSpecialCharacter(const std::string& password);

bool passwordHasUppercase(const std::string& password);

bool doesPasswordsMatch(const std::string& password, const std::string& confirmedPassword);

ErrorCode checkPasswordRules(const std::string& password);

ErrorCode checkPassword(const std::string& password, const std::string& confirmedPassword);

