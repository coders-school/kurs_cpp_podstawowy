#include "validation.hpp"

std::string getErrorMessage(const ErrorCode error) {
    switch (error) {
        case ErrorCode::Ok:
            return "OK";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password need at least 9 characters";
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Password needs at least one number";
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Password needs at least one special character";
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Password needs at least one upper case letter";
        case ErrorCode::PasswordsDoesNotMatch:
            return "Password does not match";
    }
    return "";
}

bool doesPasswordsMatch(const std::string& password, const std::string& passwordRetyped) {
    return password == passwordRetyped;
}

ErrorCode checkPasswordRules(const std::string& password) {
    // implement me
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& passwordRetyped) {
    // implement me
    return ErrorCode::Ok;
}