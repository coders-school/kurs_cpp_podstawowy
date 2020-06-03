#include "validation.hpp"
#include <algorithm>
#include <string>

std::string getErrorMessage(ErrorCode errorNumber) {
    switch (errorNumber) {
        case ErrorCode::Ok: {
            return "OK";
            break;
        }
        case ErrorCode::PasswordNeedsAtLeastNineCharacters: {
            return "Password needs at least nine characters";
            break;
        }
        case ErrorCode::PasswordNeedsAtLeastOneNumber: {
            return "Password needs at least one number";
            break;
        }
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: {
            return "Password needs at least one special character";
            break;
        }
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: {
            return "Password needs at least one uppercase letter";
            break;
        }
        case ErrorCode::PasswordsDoesNotMatch: {
            return "Passwords does not match";
            break;
        }
        default: {
            return "Unknown error";
        }
    }
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return (password == repeatedPassword);
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.size() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } else if (!std::any_of(password.begin(), password.end(), ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    } else if (!std::any_of(password.begin(), password.end(), ::ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    } else if (!std::any_of(password.begin(), password.end(), ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    } else {
        return ErrorCode::Ok;
    }
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword) {
    if (doesPasswordsMatch(password, repeatedPassword)) {
        return checkPasswordRules(password);
    }
    return ErrorCode::PasswordsDoesNotMatch;
}
