#include "validation.hpp"

std::string getErrorMessage(ErrorCode error)
{
    switch(error)
    {
        case ErrorCode::Ok:
            return "Your password is correct.\n";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters: 
            return "Your password needs at least nine characters.\n";
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Yout password needs at least one number.\n";
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Your password needs at least one special character.\n";
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Your password needs at least one upper case letter.\n";
        case ErrorCode::PasswordsDoesNotMatch:
            return "Passwords do not match.\n"; 
        default:
            return "Your password is incorrect.\n";
    }
}

bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword)
{
    return firstPassword == secondPassword;
}

