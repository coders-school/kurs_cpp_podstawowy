#pragma once

enum class ErrorCode
{
    Ok = 1,
    PasswordNeedsAtLeastNineCharacters = 2,
    PasswordNeedsAtLeastOneNumber = 3,
    PasswordNeedsAtLeastOneSpecialCharacter = 4,
    PasswordNeedsAtLeastOneUppercaseLetter = 5,
    PasswordsDoesNotMatch = 6
};

std::string getErrorMessage(ErrorCode);

// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard