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


ErrorCode checkPassword(const std::string& password,const std::string& repeatedPassword);
std::string getErrorMessage(ErrorCode result);
bool doesPasswordsMatch(const std::string& password,const std::string& repeatedPassword);
ErrorCode checkPasswordRules(const std::string& password);
