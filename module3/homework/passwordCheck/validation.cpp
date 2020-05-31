#include "validation.hpp"

std::string getErrorMessage(ErrorCode codeToShow) {
    switch (codeToShow) {
    case ErrorCode::Ok:
        return "Everything is OK";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
        break;
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords don't match";
        break;
    default:
        return "Unknown error code";
    }
}

bool doesPasswordsMatch(const std::string& firstPwd, const std::string& secondPwd) {
    return firstPwd == secondPwd;
}