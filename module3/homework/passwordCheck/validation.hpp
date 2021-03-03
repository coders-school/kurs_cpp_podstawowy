// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard
//
#pragma once
#include<string>

enum class ErrorCode{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode);
bool doesPasswordsMatch(std::string, std::string);
ErrorCode checkPasswordRules(std::string);
ErrorCode checkPassword(std::string, std::string);


