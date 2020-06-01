#include "validation.hpp"

std::string getErrorMessage(ErrorCode codeToShow) {
    switch (codeToShow) {
    case ErrorCode::Ok:
        return "OK";
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

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (!std::any_of(password.begin(), password.end(), isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    auto isPasswordHaveSpecialCharacter = [](const std::string& pwd) {
        std::string specialCharacters = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
        if (!pwd.find(specialCharacters) == std::string::npos) {
            return false;
        }

        return true;
    };

    if (!isPasswordHaveSpecialCharacter(password)) {
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