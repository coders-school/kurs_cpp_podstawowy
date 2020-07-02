#include <iostream>
#include <random>
#include "validation.hpp"

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
    std::random_device rDev;
    std::default_random_engine dre(rDev());
    std::uniform_int_distribution<int> uniformIntDist(
        errorCodeFirstElementValue,
        errorCodeLastElementValue
    );
    return static_cast<ErrorCode>(uniformIntDist(dre));
}

ErrorCode checkPassword(const std::string& actualPassword, const std::string& correctPassword) {
    if(!doesPasswordsMatch(actualPassword, correctPassword)) {
        return ErrorCode::PasswordsDoesNotMatch;
    }
    return checkPasswordRules(actualPassword);
}


