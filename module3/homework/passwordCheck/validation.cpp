#include "validation.hpp"

#include <random>

std::string getErrorMessage(ErrorCode errorToDecode) {
    switch (errorToDecode) {
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
    default:
        return "Unknown error";
    }
}

bool doesPasswordsMatch(const std::string& basePassword, const std::string& repeatedPassword) {
    return basePassword == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(static_cast<int>(ErrorCode::Ok),
                                            static_cast<int>(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter));
    return static_cast<ErrorCode>(distrib(gen));
}

ErrorCode checkPassword(const std::string& basePassword, const std::string& repeatedPassword) {
    if (!doesPasswordsMatch(basePassword, repeatedPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(basePassword);
}
