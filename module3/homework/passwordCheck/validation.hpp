#pragma once
#include <string>

enum class ErrorCode{
       Ok,
       PasswordNeedsAtLeastNineCharacters,
       PasswordNeedsAtLeastOneNumber,
       PasswordNeedsAtLeastOneSpecialCharacter,
       PasswordNeedsAtLeastOneUppercaseLetter,
       PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode error);
bool doesPasswordsMatch(const std::string& first, const std::string& second);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& first, const std::string& second);
