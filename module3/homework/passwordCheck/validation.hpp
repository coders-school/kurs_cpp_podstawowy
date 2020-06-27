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
bool doesPasswordsMatch(std::string password, std::string repeated_password);
ErrorCode checkPasswordRules(std::string const password);
ErrorCode checkPassword(std::string const password,
                    std::string const repeated_password);




