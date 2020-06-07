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

std::string getErrorMessage(ErrorCode error);
bool doesPasswordsMatch(const std::string& first, const std::string& second);
ErrorCode checkPasswordRules(const std::string& password);
ErrorCode checkPassword(const std::string& first, const std::string& second);
// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard