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

bool  doesPasswordsMatch(std::string& firstPassword, std::string& secondPassword);
ErrorCode checkPasswordRules(std::string& password);
ErrorCode checkPassword(std::string& firstPassword, std::string& secondPassword);
std::string getErrorMessage(ErrorCode code);
