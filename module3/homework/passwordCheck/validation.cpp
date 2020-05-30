#include "validation.hpp"

std::string getErrorMessage(ErrorCode errorCode)
{
    switch (errorCode)
    {
        case ErrorCode::Ok:
            return "OK";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password needs at least nine characters.";
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Password needs at least one number.";
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Password needs at least one special character.";
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Password needs at least one uppercase letter.";
        case ErrorCode::PasswordsDoesNotMatch:
            return "Password does not match.";
        default:
            return "Error Code undefined.";
    }
}

bool doesPasswordsMatch(std::string password, std::string repeatedPassword) {
    return false;
}

ErrorCode checkPasswordRules(std::string password) {
    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string password, std::string repeatedPassword) {
    return ErrorCode::Ok;
}