#include "validation.hpp"

#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>

std::string getErrorMessage(ErrorCode error) {
    switch (error) {
    case ErrorCode::Ok:
        return "Ok";
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Error, Password need at least 9 characters!";
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Error, Password need at least 1 number!";
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Error, Password need at least one special character!";
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Error, Password need at least uppercase letter!";
    case ErrorCode::PasswordsDoesNotMatch:
        return "Error, password does not match!";
    default:
        return "Undefined Error!";
    }
}

bool doesPasswordsMatch(const std::string input, const std::string password) {
    return input == password;
}

std::string checkPasswordRules(const std::string& password) {
    srand(time(NULL));
    int random = rand() % 6;
    return getErrorMessage(ErrorCode(random));
}

std::string checkPassword(std::string input, std::string password) {
    if (!doesPasswordsMatch(input, password)) {
        return getErrorMessage(ErrorCode::PasswordsDoesNotMatch);
    }
    return checkPasswordRules(input);
}