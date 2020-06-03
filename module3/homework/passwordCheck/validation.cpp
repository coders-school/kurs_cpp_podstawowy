#include "validation.hpp"
// TODO: Put implementations here
#include <algorithm>
#include <cctype>
#include <string>

std::string getErrorMessage(ErrorCode code) {
    switch (code) {
    case Ok:
        return "Ok";
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

bool doesPasswordsMatch(std::string& password1, std::string& password2) {
    return password1 == password2;
}

ErrorCode checkPasswordRules(std::string& password) {
    if (password.size() < 9)
        return PasswordNeedsAtLeastNineCharacters;
    if (std::none_of(password.begin(), password.end(), [&](char a) { return isdigit(a) }))
        return PasswordNeedsAtLeastOneNumber;
    if (std::none_of(password.begin(), password.end(), [&](char a) { return isupper(a) }))
        return PasswordNeedsAtLeastOneUppercaseLetter;
    if (std::none_of(password.begin(), password.end(), [&](char a) { return ispunct(a) }))
        return PasswordNeedsAtLeastOneSpecialCharacter;
    return Ok;
}

ErrorCode checkPassword(std::string& password1, std::string& password2) {
    if (!doesPasswordsMatch)
        return PasswordsDoesNotMatch;

    return checkPasswordRules(password1);
}
