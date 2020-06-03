#include "validation.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>

std::string getErrorMessage(ErrorCode code) {

    switch (code) {
    case ErrorCode::Ok:
        return "OK";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        return "Error, password should consist of at least nine characters!";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        return "Error, password should consist of at least 1 number!";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        return "Error, password should consist of at least 1 special character!";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        return "Error, password should consist of at least 1 uppercase letter!";
        break;
    case ErrorCode::PasswordsDoesNotMatch:
        return "Error, passwords do not match!";
        break;
    }

    return "";
}

bool doesPasswordsMatch(std::string const & pass1,
    std::string const & pass2) {

        return pass1 == pass2;
}

ErrorCode checkPasswordRules(std::string const & pass) {

    if (pass.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;

    auto consistsNumber = std::any_of(begin(pass), end(pass), [&](const char &c) {
            return std::isdigit(c);
        });

    if (!consistsNumber)
        return ErrorCode::PasswordNeedsAtLeastOneNumber;

    std::string specialChars = R"( !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)";
    auto consistsSpecialChar = std::any_of(begin(pass), end(pass), [&](const char &c) {
            return (specialChars.find(c) != std::string::npos);
        });

    if (!consistsSpecialChar)
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;

    auto consistsUppercaseLetter = std::any_of(begin(pass), end(pass), [&](const char &c) {
            return std::isupper(c);
        });

    if (!consistsUppercaseLetter)
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string const & pass1,
    std::string const & pass2) {

    if (!doesPasswordsMatch(pass1, pass2))
        return ErrorCode::PasswordsDoesNotMatch;
        
    return checkPasswordRules(pass1);
}
