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

std::string getErrorMessage(ErrorCode errorCode);
bool doesPasswordsMatch(std::string password, std::string repeatedPassword);
ErrorCode checkPasswordRules(std::string password);
ErrorCode checkPassword(std::string password, std::string repeatedPassword);
