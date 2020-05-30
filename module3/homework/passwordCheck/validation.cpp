#include "validation.hpp"

std::string getErrorMessage(ErrorCode error_code) {
    return "";
}

bool doesPasswordsMatch(std::string password, std::string repeatedPassword) {
    return false;
}

ErrorCode checkPasswordRules(std::string password) {
    return Ok;
}

ErrorCode checkPassword(std::string password, std::string repeatedPassword) {
    return Ok;
}