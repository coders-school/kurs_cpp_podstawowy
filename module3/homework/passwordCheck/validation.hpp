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

std::string getErrorMessage(ErrorCode code);
bool doesPasswordMatch(std::string password, std::string repeated_password);
ErrorCode checkPasswordRules(std::string const password);
ErrorCode checkPassword(std::string const password,
                    std::string const repeated_password);




