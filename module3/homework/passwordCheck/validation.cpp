#include "validation.hpp"

std::string getErrorMessage(ErrorCode codeToShow) {
    switch (codeToShow) {
    case ErrorCode::Ok:
        return "OK";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords don't match";
    default:
        return "Unknown error code";
    }
}

bool doesPasswordsMatch(const std::string& firstPwd, const std::string& secondPwd) {
    return firstPwd == secondPwd;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (!std::any_of(password.begin(), password.end(), isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if (std::none_of(password.begin(), password.end(), [](char sign) { return isprint(sign) && !isalnum(sign); })) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (!std::any_of(password.begin(), password.end(), isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPwd, const std::string& secondPwd) {
    if (!doesPasswordsMatch(firstPwd, secondPwd)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(firstPwd);
}
