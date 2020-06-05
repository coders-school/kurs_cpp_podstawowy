// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard
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

std::string getErrorMessage(ErrorCode code);

bool doesPasswordsMatch(const std::string&, const std::string&);

ErrorCode checkPasswordRules(const std::string&);

ErrorCode checkPassword(const std::string&, const std::string&);
