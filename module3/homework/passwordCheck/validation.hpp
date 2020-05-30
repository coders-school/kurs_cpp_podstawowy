#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cctype>
#include <algorithm>

enum ErrorCode
{
	Ok = 0,
	PasswordNeedsAtLeastNineCharacters,
	PasswordNeedsAtLeastOneNumber,
	PasswordNeedsAtLeastOneSpecialCharacter,
	PasswordNeedsAtLeastOneUppercaseLetter,
	PasswordsDoesNotMatch
};

std::string getErrorMessage(const ErrorCode& err);
bool doesPasswordsMatch(const std::string& password1, const std::string& password2);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& password1, const std::string& password2);