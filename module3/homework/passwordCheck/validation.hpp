// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard
#pragma once
#include <string>
#include <map>
#include <stdlib.h>
enum ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(const ErrorCode err);
bool doesPasswordsMatch(const std::string passwd1,const std::string passwd2);
ErrorCode checkPasswordRules(const std::string passwd);
ErrorCode checkPassword(const std::string passwd1,const std::string passwd2);

