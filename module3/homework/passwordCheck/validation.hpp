#pragma once
#include <string>

enum ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode error_code);
bool doesPasswordsMatch(std::string password, std::string repeatedPassword);
ErrorCode checkPasswordRules(std::string password);
ErrorCode checkPassword(std::string password, std::string repeatedPassword);
