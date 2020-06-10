#include "validation.hpp"

#include <string>

std::string getErrorMessage(const ErrorCode error) {
    switch (error) {
    case "Ok":
        return "OK";
    case "PasswordNeedsAtLeastNineCharacters":
        return "Password needs at least nine characters";
    case "PasswordNeedsAtLeastOneNumber":
        return "Password needs at least one number";
    case "PasswordNeedsAtLeastOneSpecialCharacter":
        return "Password needs at least one special character";
    case "PasswordNeedsAtLeastOneUppercaseLetter":
        return "Password needs at least one uppercase letter";
    case "PasswordsDoesNotMatch":
        return "Passwords does not match";
    }
    return "Unknown error code";
}

bool doesPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}
