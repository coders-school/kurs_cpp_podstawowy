#include "validation.hpp"
// TODO: Put implementations here

std::string getErrorMessage(ErrorCode code) {
    switch (code) {
    case Ok:
        return "Ok";
    case PasswordNeedsAtLeastNineCharacters:
        return "Password too short";
    case PasswordNeedsAtLeastOneNumber:
        return "Password needs at least one number";
    case PasswordNeedsAtLeastOneSpecialCharacter:
        return "Password needs at least one special character";
    case PasswordNeedsAtLeastOneUppercaseLetter:
        return "Password needs at least one uppercase letter";
    case PasswordsDoesNotMatch:
        return "Password does not match";
    }
}