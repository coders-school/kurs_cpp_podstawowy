#include "validation.hpp"

std::string getErrorMessage(ErrorCode code)
{
    std::string result;

    switch (code)
    {
        case ErrorCode::Ok:
            result = "OK";
            break;
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            result = "Password requires at least 9 characters";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            result = "Password requires at least one number";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            result = "Password requires at least special character";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            result = "Password requires at least one uppercase letter";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            result = "Password does not match";
            break;
        default:
            result = "Unknown error";
            break;
    }

    return result;
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword)
{
    return password == repeatedPassword;
}
