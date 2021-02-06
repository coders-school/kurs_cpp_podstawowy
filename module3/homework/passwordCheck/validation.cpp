#include "validation.hpp"
// TODO: Put implementations here

ErrorCode checkPassword(const std::string password, const std::string checkedPassword) {
    if (doesPasswordsMatch(password, checkedPassword)) {
        return checkPasswordRules(checkedPassword);

    } else {
        return ErrorCode::PasswordsDoesNotMatch;
    }
}
std::string getErrorMessage(ErrorCode errorCode) {
    switch (errorCode) {
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return "Error: Password Needs At Least Nine Characters\n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return "Error: Password Needs At Least One Number\n";
            break;

        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return "Error: Password Needs At Least One Special Character\n";
            break;
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return "Error: Password Needs At Least One Uppercase Letter\n";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Error: Passwords Does Not Match\n";
            break;
        case ErrorCode::Ok:
            return "OK";
            break;
        default:
            return "";
            break;
    }
}
bool doesPasswordsMatch(const std::string password, const std::string checkedPassword) {
    if (password == checkedPassword) {
        return true;
    } else {
        return false;
    }
}
ErrorCode checkPasswordRules(const std::string &input) {
    bool hasUpper = false;
    bool hasDigit = false;
    bool specialCharacter = false;
    std::string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    for (int i = 0; i < input.length(); i++) {
        if (isupper(input[i])) {
            hasUpper = true;
        }
        if (isdigit(input[i])) {
            hasDigit = true;
        }
        size_t special = input.find_first_not_of(normalChars);

        if (special != std::string::npos) {
            specialCharacter = true;
        }
    }

    if (input.length() < 9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } else if (!hasDigit) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    } else if (!specialCharacter) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    } else if (!hasUpper) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    } else {
        return ErrorCode::Ok;
    }
}