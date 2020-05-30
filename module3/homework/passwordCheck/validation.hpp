#pragma once
#include <algorithm>
#include <cctype>

enum class ErrorCode
{
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode);

bool doesPasswordsMatch(const std::string&, const std::string&);

ErrorCode checkPasswordRules(const std::string&);

// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard