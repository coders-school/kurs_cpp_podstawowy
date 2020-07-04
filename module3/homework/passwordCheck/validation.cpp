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
        case ErrorCode::Ok: {
            return "Ok";
        }
        case ErrorCode::PasswordNeedsAtLeastNineCharacters: {
            return "Password Needs At Least Nine Characters";
        }
        case ErrorCode::PasswordNeedsAtLeastOneNumber: {
            return "Password Needs At Least One Number";
        }
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: {
            return "Password Needs At Least One Special Character";
        }
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: {
            return "Password Needs At Least One Uppercase Letter";
        }
        case ErrorCode::PasswordsDoesNotMatch: {
            return "Passwords Does Not Match";
        }
        default: {
            return std::string("getErrorMessage() error!\n");
        }
    }
}

bool doesPasswordsMatch(const std::string& input1, const std::string& input2) {
    return !(static_cast<bool>(input1.compare(input2)));
}

ErrorCode checkPasswordRules(const std::string& input) {
    if(input.length() < minimumPasswordLength) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    const auto it1 = input.cbegin();
    const auto it2 = input.cend();
    if(!std::any_of(it1, it2, ::isdigit)) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if(!std::any_of(it1, it2, ::ispunct)) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if(!std::any_of(it1, it2, ::isupper)) {
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
