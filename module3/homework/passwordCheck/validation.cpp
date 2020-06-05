#include "validation.hpp"
// TODO: Put implementations here
#include <algorithm>
#include <cctype>

std::string getErrorMessage(ErrorCode code) {
    switch (code) {
    case Ok:
        return "OK";
    case PasswordNeedsAtLeastNineCharacters:
        return "Password too short";
    case PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
    case PasswordsDoesNotMatch:
        return "Password does not match";
    }
}

bool doesPasswordsMatch(const std::string& password1, const std::string& password2) {
    return password1 == password2;
}

ErrorCode checkPasswordRules(const std::string& password) {
    if (password.size() < 9)
        return PasswordNeedsAtLeastNineCharacters;
    if (std::none_of(password.begin(), password.end(), [&](char a) { return isdigit(a); }))
        return PasswordNeedsAtLeastOneNumber;
    if (std::none_of(password.begin(), password.end(), [&](char a) { return isupper(a); }))
        return PasswordNeedsAtLeastOneUppercaseLetter;
    if (std::none_of(password.begin(), password.end(), [&](char a) { return ispunct(a); }))
        return PasswordNeedsAtLeastOneSpecialCharacter;
    return Ok;
}

ErrorCode checkPassword(const std::string& password1, const std::string& password2) {
    if (!doesPasswordsMatch(password1, password2))
        return PasswordsDoesNotMatch;

    return checkPasswordRules(password1);
}
