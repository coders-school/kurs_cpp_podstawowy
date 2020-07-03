#include "validation.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>

constexpr int minimumPasswordLength = 9;

std::string getErrorMessage(const ErrorCode& input) {
// Possible other implementation with a std::map<ErrorCode, std::string>
    std::string returnValue;
    switch(input) {
        case ErrorCode::Ok:
            return "Ok";
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
            return "Password Needs At Least One Uppercase Letter";
            break;
        case ErrorCode::PasswordsDoesNotMatch:
            return "Passwords Does Not Match";
            break;
    }
    return std::string("getErrorMessage() error!\n");
}

bool doesPasswordsMatch(const std::string& input1, const std::string& input2) {
    return !(static_cast<bool>(input1.compare(input2)));
}

ErrorCode checkPasswordRules(const std::string& input) {
    if(input.length() < minimumPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    const auto it1 = input.begin();
    const auto it2 = input.end();
    if(!std::any_of(it1, it2, isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if(!std::any_of(it1, it2, ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if(!std::any_of(it1, it2, isupper)) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& actualPassword, const std::string& correctPassword) {
    if(!doesPasswordsMatch(actualPassword, correctPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(actualPassword);
}
