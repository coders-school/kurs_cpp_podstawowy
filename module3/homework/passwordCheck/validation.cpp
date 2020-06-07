#include "validation.hpp"

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

ErrorCode checkPasswordRules(const std::string& password) {
    switch (std::rand() % 5) {
    case 0:
        return ErrorCode::Ok;
    case 1:
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    case 2:
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    case 3:
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
}

ErrorCode checkPassword(const std::string& first, const std::string& second) {
    if (!doesPasswordsMatch(first, second)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(first);
}
