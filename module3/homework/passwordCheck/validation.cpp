#include "validation.hpp"
#include <string>
#include <ostream>
#include <sstream>

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

bool doesPasswordsMatch(std::string& firstPassword, std::string& secondPassword)
{
    return firstPassword == secondPassword;
}

ErrorCode checkPasswordRules(std::string& password)
{
    return ErrorCode::Ok;
}

ErrorCode checkPassword(std::string& firstPassword, std::string& secondPassword)
{
    if(doesPasswordsMatch(firstPassword,secondPassword)) return ErrorCode::Ok;
    else return ErrorCode::PasswordsDoesNotMatch;
}
std::string getErrorMessage(ErrorCode code)
{
    std::ostringstream stream;
    stream << code;
    return stream.str();
}
