#include "validation.hpp"

#include <algorithm>
#include <string>

std::string getErrorMessage(const ErrorCode error) {
    switch (error) {
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
        return "Passwords does not match";
    }
    return "Unknown error";
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    else if (std::any_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    else if (std::any_of(password.begin(), password.end(), ::isalnum)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    else if (std::any_of(password.begin(), password.end(), ::isupper)) {
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
