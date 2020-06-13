#include "validation.hpp"

#include <algorithm>
#include <ctime>

std::string getErrorMessage(const ErrorCode message) {
    switch (message) {
        case ErrorCode::Ok: {
            return "OK";
        }
        case ErrorCode::PasswordNeedsAtLeastNineCharacters: {
            return "Password needs at least nine characters";
        }
        case ErrorCode::PasswordNeedsAtLeastOneNumber: {
            return "Password needs at least one number";
        }
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: {
            return "Password needs at least one special character";
        }
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: {
            return "Password needs at least one uppercase letter";
        }
        case ErrorCode::PasswordsDoesNotMatch: {
            return "Passwords don't match";
        }
        default: {
            return "Unknown error code";
        }
    }
}

bool doesPasswordsMatch(std::string firstPass, std::string secondPass) {
    return firstPass == secondPass;
}

ErrorCode checkPasswordRules(std::string password) {
    auto start = cbegin(password);
    auto stop = cend(password);

    if (password.size() < passwordMinimumLength)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    if (std::none_of(start, stop, [](unsigned char letter) { return std::isdigit(letter); }))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    if (std::none_of(start, stop, [](unsigned char letter) { return std::isupper(letter); }))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    if (std::none_of(start, stop, [](unsigned char letter) { return std::ispunct(letter); }))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string firstPass, std::string secondPass) {
    if (!doesPasswordsMatch(firstPass, secondPass))
        return ErrorCode::PasswordsDoesNotMatch;

    ErrorCode result = checkPasswordRules(firstPass);

    return result;
}

