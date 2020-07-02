#include "validation.hpp"

constexpr const int minPasswordLength = 9;

std::string getErrorMessage(const ErrorCode errorText) {
    switch (errorText) {
    case ErrorCode::Ok:
        return "OK";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharackters:
        return "Password must be at least 9 charackters long.";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password must have at least one capital letter.";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharackter:
        return "Password must have at least one special charackter.";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password must have at least one uppercase letter.";
        break;
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords does not match.";
        break;
    default:
        return "Unknown Error! Please contact the administrator.";
        break;
    }
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < minPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharackters;
    }
    if (std::any_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::any_of(password.begin(), password.end(), ::isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharackter;
    }
    if (std::any_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    else {
        return ErrorCode::Ok;
    }
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword) {
    if (!doesPasswordsMatch(password, repeatedPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(password);
}
