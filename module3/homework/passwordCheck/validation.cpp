#include "validation.hpp"

#include <algorithm>
#include <iostream>

std::string getErrorMessage(const ErrorCode& caseOfError) {
    switch (caseOfError) {
    case ErrorCode::Ok:
        return "OK";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Password needs at least nine characters.";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number.";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character.";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
        break;
    case ErrorCode::PasswordsDoesNotMatch:
        return "Passwords do not match.";
        break;
    default:
        return "Error";
    }
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& input) {
    const auto front = input.cbegin();
    const auto end = input.cend();
    if (input.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } else if (input.find_first_of("0123456789") != std::string::npos) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    } else if (!std::any_of(front, end, ::ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    } else if (!std::any_of(front, end, ::isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    } else {
        return ErrorCode::Ok;
    }
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassword) {
    if (doesPasswordsMatch(password, repeatedPassword) == false) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(password);
}
