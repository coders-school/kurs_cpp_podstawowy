#include "validation.hpp"
#include <string>
#include <algorithm>


std::string getErrorMessage(ErrorCode Error) {
    switch (static_cast<int>(Error)) {
        case 100:
            return "OK";
            break;
        case 101:
            return "Password Needs At Least Nine Characters";    
            break;
        case 102:
            return "Password Needs At Least One Number";
            break;
        case 103:
            return "Password Needs At Least One Special Character";
            break;
        case 104:
            return "Password Needs A Least One Uppercase Letter";
            break;
        case 105:
            return "Passwords Does Not Match";
            break;
        default:
        return "UNDEFINING ERROR";
    }
}

bool doesPasswordsMatch(std::string password, std::string repeatedPassword) {
    if (password==repeatedPassword) {
        return true;
    }
    else {
        return false;
    }
}

ErrorCode checkPasswordRules(std::string password) {
    if (password.size()<9) {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::any_of(password.begin(), password.end(), [](char c){ return std::isdigit(c); })==0) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::any_of(password.begin(), password.end(), [](char c){ return std::ispunct(c); })==0) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::any_of(password.begin(), password.end(), [](char c){ return std::isupper(c); })==0) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
  return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string password, std::string repeatedPassword) {
    if (doesPasswordsMatch(password, repeatedPassword)) {
        return checkPasswordRules(password);
    }
    else {
        return ErrorCode::PasswordsDoesNotMatch;
    }
}
