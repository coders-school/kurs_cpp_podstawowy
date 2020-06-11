#pragma once
#include <iostream>
#include <string>

enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch,

};

std::string getErrorMessage(const ErrorCode& code);
bool doesPasswordsMatch(const std::string& pass1, const std::string& pass2);
ErrorCode checkPasswordRules(const std::string& pass);
ErrorCode checkPassword(const std::string& pass1, const std::string& pass2);
