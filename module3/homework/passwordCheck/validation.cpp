#include "validation.hpp"
#include <random>

std::string getErrorMessage(ErrorCode code) {
    if(code == ErrorCode::Ok) {
        return "OK";
    } else if(code == ErrorCode::PasswordNeedsAtLeastNineCharacters) {
        return "Password Needs At Least Nine Characters";
    } else if(code == ErrorCode::PasswordNeedsAtLeastOneNumber) {
        return "Password Needs At Least One Number";
    } else if(code == ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter) {
        return "Password Needs At Least One Special Character";
    } else if(code == ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter) {
        return "Password Needs At Least One Uppercase Letter";
    } else if(code == ErrorCode::PasswordsDoesNotMatch) {
        return "Passwords Does Not Match";
    }
}

bool doesPasswordsMatch(const std::string& first_pass, const std::string& second_pass) {
    return first_pass == second_pass;
}

ErrorCode checkPasswordRules(const std::string& password) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(static_cast<int>(ErrorCode::Ok), static_cast<int>(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter));

    return static_cast<ErrorCode>(dis(gen));
}

ErrorCode checkPassword(const std::string& first_pass, const std::string& second_pass) {
    if(doesPasswordsMatch(first_pass, second_pass)) {
        return checkPasswordRules(first_pass);
    } else {
        return ErrorCode::PasswordsDoesNotMatch;
    }
}