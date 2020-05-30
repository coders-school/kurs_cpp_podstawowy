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

// https://www.ipvoid.com/password-special-characters/
// https://owasp.org/www-community/password-special-characters
const std::string specialCharacters = " !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~";
const int minPasswordLength = 9;

std::string getErrorMessage(ErrorCode errorCode);
bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword);
