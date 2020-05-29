#include "validation.hpp"

std::string getErrorMessage(const ErrorCode error) {
    // implement me
    return "";
}

bool doesPasswordsMatch(const std::string& password, const std::string& passwordRetyped) {
    // implement me
    return false;
}

ErrorCode checkPasswordRules(const std::string& password) {
    // implement me
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& password, const std::string& passwordRetyped) {
    // implement me
    return ErrorCode::Ok;
}