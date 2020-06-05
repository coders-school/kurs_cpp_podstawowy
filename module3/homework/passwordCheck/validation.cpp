#include "validation.hpp"

std::string getErrorMessage(const ErrorCode code) {
    switch (code) {
    case ErrorCode::Ok:
        return "Every think is ok, thanks bye";

    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password is too short, needs at least 9 characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";

    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";

    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";

    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords doesnt match";

    default:
        return "unknown error, better contact the service";
    }
}

bool doesPasswordsMatch(const std::string& firstPassword, const std::string& secondPassword) {
    return firstPassword == secondPassword;
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword) {
    if (!doesPasswordsMatch(firstPassword, secondPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    } else {
        return checkPasswordRules(firstPassword);
    }
}
ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < charAtLeast) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::all_of(password.begin(), password.end(), ::isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}
