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

std::string getErrorMessage(ErrorCode err);
bool doesPasswordsMatch(std::string password1, std::string password2);
ErrorCode checkPasswordRules(std::string password);
ErrorCode checkPassword(std::string password1, std::string password2);