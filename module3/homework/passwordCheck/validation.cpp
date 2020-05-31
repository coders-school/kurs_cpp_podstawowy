#include "validation.hpp"

std::string getErrorMessage(const ErrorCode errorCode)
{
    return std::string();
}

bool doesPasswordsMatch(const std::string& password, const std::string& confirmedPassword)
{
    return false;
}

ErrorCode checkPassword(const std::string& password, const std::string& confirmedPassword)
{
    return ErrorCode();
}

ErrorCode checkPasswordRules(const std::string& password)
{
    return ErrorCode();
}
