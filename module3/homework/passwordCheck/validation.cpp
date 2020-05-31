#include <algorithm>
#include <ostream>
#include <sstream>
#include <string>
#include "validation.hpp"

std::ostream& operator<<(std::ostream& os, ErrorCode value)
{
    switch (value)
    {
        case ErrorCode::Ok:
            return os << "OK";
        case ErrorCode::PasswordNeedsAtLeastNineCharacters:
            return os << "PasswordNeedsAtLeastNineCharacters";
        case ErrorCode::PasswordNeedsAtLeastOneNumber:
            return os << "PasswordNeedsAtLeastOneNumber";
        case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
            return os << "PasswordNeedsAtLeastOneSpecialCharacter";
        case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
            return os << "PasswordNeedsAtLeastOneUppercaseLetter";
        case ErrorCode::PasswordsDoesNotMatch:
            return os << "PasswordsDoesNotMatch";
    }
    return os;
}

bool doesPasswordsMatch(const std::string& firstPassword,const std::string& secondPassword)
{
    return firstPassword == secondPassword;
}

bool hasSpecialChar(const std::string& str)
{
    return std::any_of(str.begin(), str.end(), [](char ch) { return (!isalnum(ch) || ch == '_'); });
}

bool hasUpperCase(const std::string& str)
{
    return std::any_of(str.begin(), str.end(), [](char ch) { return (isupper(ch)); });
}

bool hasDigit(const std::string& str)
{
    return std::any_of(str.begin(), str.end(), [](char ch) { return (isdigit(ch)); });
}

ErrorCode checkPasswordRules(const std::string& password)
{
    if (password.size() < 9)
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    else if (!hasSpecialChar(password))
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    else if (!hasUpperCase(password))
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    else if (!hasDigit(password))
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    return ErrorCode::Ok;
}

ErrorCode checkPassword(const std::string& firstPassword, const std::string& secondPassword)
{
    if (doesPasswordsMatch(firstPassword, secondPassword))
        return ErrorCode::Ok;
    else
        return ErrorCode::PasswordsDoesNotMatch;
}
std::string getErrorMessage(ErrorCode code)
{
    std::ostringstream stream;
    stream << code;
    return stream.str();
}
