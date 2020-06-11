#include "validation.hpp"
#include <map>
#include <algorithm>
#include <iterator>
#include <cctype>

static constexpr int MinPasswordLen = 9;

static const std::map<ErrorCode, std::string> ErrorMessagesEn {
    {ErrorCode::Ok, "Ok"},
    {ErrorCode::PasswordNeedsAtLeastNineCharacters, "Password needs at least nine characters."},
    {ErrorCode::PasswordNeedsAtLeastOneNumber, "Password needs at least one number."},
    {ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter, "Password needs at least one special character."},
    {ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter, "Password needs at least one uppercase letter."},
    {ErrorCode::PasswordsDoesNotMatch, "Passwords do not match."}
};



std::string getErrorMessage(ErrorCode validationError)
{
    return ErrorMessagesEn.at(validationError);
}

bool doesPasswordsMatch(const std::string& passwd1, const std::string& passwd2)
{
    bool result = true;

    if(passwd1.compare(passwd2)) {
        result = false;
    }
    return result;
}

ErrorCode checkPasswordRules(const std::string& passwd)
{
    if(passwd.length() < MinPasswordLen)
    {
        return ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if(!std::any_of(passwd.cbegin(), passwd.cend(), [](const char c) { return std::isdigit(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if(!std::any_of(passwd.cbegin(), passwd.cend(), [](char c) { return (std::isprint(c) && !std::isalnum(c)); })) {
        return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if(!std::any_of(passwd.cbegin(), passwd.cend(), [](char c) { return std::isupper(c); })) {
        return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }

    return ErrorCode::Ok;
}

ErrorCode  checkPassword(const std::string& passwd1, const std::string& passwd2)
{
    ErrorCode errodCode = ErrorCode::PasswordsDoesNotMatch;

    if (doesPasswordsMatch(passwd1, passwd2))
    {
        errodCode = checkPasswordRules(passwd1);
    }
    return errodCode;

}

