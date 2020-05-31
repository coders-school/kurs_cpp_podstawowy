// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard
#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

enum class ErrorCode{

    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode error);
bool doesPasswordsMatch(std::string firstPassword, std::string secondPassword);
ErrorCode checkPasswordRules(std::string password);
ErrorCode checkPassword(std::string firstPassword, std::string secondPassword);
