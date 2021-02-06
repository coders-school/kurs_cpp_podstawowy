// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard
#pragma once
#include <string>
enum class ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

ErrorCode checkPassword(const std::string, const std::string);
std::string getErrorMessage(ErrorCode);
bool doesPasswordsMatch(const std::string, const std::string);
ErrorCode checkPasswordRules(const std::string &);