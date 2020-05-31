#pragma once
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
std::ostream& operator << (std::ostream&, ErrorCode);

bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& firstPassword,const std::string& secondPassword);
std::string getErrorMessage(ErrorCode code);
