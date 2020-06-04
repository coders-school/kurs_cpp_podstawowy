#include "validation.hpp"

#include <algorithm>
#include <ctime>


std::string getErrorMessage(ErrorCode e) {

    std::string errMsg = "";

    switch (e) {

        case ErrorCode::Ok: {

            errMsg = "OK";
            break;
        }

        case ErrorCode::PasswordNeedsAtLeastNineCharacters: {

            errMsg = "PasswordNeedsAtLeastNineCharacters";
            break;
        }

        case ErrorCode::PasswordNeedsAtLeastOneNumber: {

            errMsg = "PasswordNeedsAtLeastOneNumber";
            break;
        }

        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: {

            errMsg = "PasswordNeedsAtLeastOneSpecialCharacter";
            break;
        }

        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: {

            errMsg = "PasswordNeedsAtLeastOneUppercaseLetter";
            break;
        }

        case ErrorCode::PasswordsDoesNotMatch: {

            errMsg = "PasswordsDoesNotMatch";
        }

    }

    return errMsg;
}



bool doesPasswordsMatch(const std::string&pass, const std::string& repPass) {

    return pass == repPass;
}



ErrorCode checkPasswordRules(const std::string& pass) {

    if (pass.size() < 9) {

        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }

    if (std::any_of(pass.cbegin(), pass.cend(), [](const char& c){if (c > 47 && c < 58) {return true;} else {return false;};})) {

        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }

    if (std::any_of(pass.cbegin(), pass.cend(), [](const char& c){if ((c > 32 && c < 48) && (c > 57 && c < 65)) {return true;} else {return false;};})) {

        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }

    if (std::any_of(pass.cbegin(), pass.cend(), [](const char& c){if (c > 64 && c < 91) {return true;} else {return false;};})) {

        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}



ErrorCode checkPassword(const std::string& pass, const std::string& repPass) {

    if (doesPasswordsMatch(pass, repPass) == false) {

        return ErrorCode::PasswordsDoesNotMatch;
    }

    return checkPasswordRules(pass);
}


