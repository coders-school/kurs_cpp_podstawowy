#include <algorithm>
#include <string>
#include "validation.hpp"

std::string getErrorMessage(ErrorCode Error) {
    switch (Error) {
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
            return "Password Needs A Least One Uppercase Letter";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Passwords Does Not Match";
            break;
        default:
        return "UNDEFINING ERROR";
    }
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    if (password == repeatedPassword) {
        return true;
    }
    return false;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.size() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::any_of(password.begin(), password.end(), [](char c){ return std::isdigit(c); }) == 0) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::any_of(password.begin(), password.end(), [](char c){ return std::ispunct(c); }) == 0) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::any_of(password.begin(), password.end(), [](char c){ return std::isupper(c); }) == 0) {
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
