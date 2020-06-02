#include "validation.hpp"

#include <algorithm>

std::string getErrorMessage(const ErrorCode errorCode) {
    switch (errorCode) {
    case ErrorCode::Ok:
        return "OK";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password Needs At Least Nine Characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password Needs At Least One Number";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password Needs At Least One Special Character";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password Needs At Least One Uppercase Letter";
        break;
    }

    return "Passwords Does Not Match";
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.size() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (!std::any_of(password.begin(), password.end(), isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (!std::any_of(password.begin(), password.end(), ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (!std::any_of(password.begin(), password.end(), isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword) {
    if (doesPasswordsMatch(password, repeatedPassword)) {
        return checkPasswordRules(password);
    }

    return ErrorCode::PasswordsDoesNotMatch;
}
