#include "validation.hpp"

#include <algorithm>
#include <cctype>

std::string getErrorMessage(ErrorCode error) {
    switch (error) {
    case ErrorCode::Ok:
        return "OK";

    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters!";

    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number!";

    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character!";

    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Passwords needs at least one uppercase letter!";

    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords do not match!";
    }
    return " ";
}

bool doesPasswordsMatch(const std::string& first, const std::string& second) {
    return (first == second);
}

bool my_isdigit(char c) {
    return std::isdigit(static_cast<unsigned char>(c));
}

bool my_ispunct(char c) {
    return std::ispunct(static_cast<unsigned char>(c));
}

bool my_isupper(char c) {
    return std::isupper(static_cast<unsigned char>(c));
}

ErrorCode checkPasswordRules(const std::string& password) {
    const int MIN_PASSWORD_LENGHT = 9;
    if (password.size() < MIN_PASSWORD_LENGHT) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(begin(password), end(password), my_isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::none_of(begin(password), end(password), my_ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(begin(password), end(password), my_isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& first, const std::string& second) {
    if (!doesPasswordsMatch(first, second)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(first);
}
