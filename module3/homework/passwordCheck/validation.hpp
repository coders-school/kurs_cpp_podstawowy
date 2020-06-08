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

bool doesPasswordsMatch(std::string password, std::string repeatedPassword);
ErrorCode checkPassword(std::string password, std::string repeatedPassword);
ErrorCode checkPasswordRules(std::string password);
std::string getErrorMessage(ErrorCode result); 


