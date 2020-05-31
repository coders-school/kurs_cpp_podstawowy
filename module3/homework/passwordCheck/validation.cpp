#include <algorithm>
#include <cctype>

#include "validation.hpp"

std::string getErrorMessage(const ErrorCode error) {
    switch (error) {
        case ErrorCode::Ok:
            return "OK";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Password needs at least 9 characters";
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
    if (password.size() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } else if (!std::any_of(password.begin(), password.end(), isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    } else if (password.find_first_of("!@#$%^&*") == std::string::npos) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    } else if (!std::any_of(password.begin(), password.end(), isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& passwordRetyped) {
    if (!doesPasswordsMatch(password, passwordRetyped)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(password);
}