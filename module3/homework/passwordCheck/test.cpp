#include "gtest/gtest.h"
#include "validation.hpp"

std::string EMPTY_PASSWORD = "";
std::string PROPER_PASSWORD = "abcABC123!@#";
std::string TOO_SHORT_PASSWORD = "12345678";
std::string NO_NUMBERS_PASSWORD = "abcABCxxx!@#";
std::string NO_SPECIAL_CHARS_PASSWORD = "abcABC123xxx";
std::string NO_UPPERCASE_PASSWORD = "abcxxx123!@#";


TEST(DoesPasswordsMatchTests, returnsTrueForIdenticalPasswords) {
    EXPECT_TRUE(doesPasswordsMatch(EMPTY_PASSWORD, EMPTY_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(PROPER_PASSWORD, PROPER_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD));
}

TEST(DoesPasswordsMatchTests, returnsFalseForDifferentPasswords) {
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, PROPER_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, TOO_SHORT_PASSWORD));
}

TEST(checkPasswordRulesTests, returnsStringSafetyPolicyCodes) {
    EXPECT_EQ(checkPasswordRules(EMPTY_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_EQ(checkPasswordRules(TOO_SHORT_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);

    EXPECT_EQ(checkPasswordRules(NO_NUMBERS_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneNumber);
    EXPECT_EQ(checkPasswordRules(NO_SPECIAL_CHARS_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
    EXPECT_EQ(checkPasswordRules(NO_UPPERCASE_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);

    EXPECT_EQ(checkPasswordRules(PROPER_PASSWORD), ErrorCode::Ok);
}

TEST(checkPasswordTests, returnsStringSafetyPolicyCodes) {

    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);

    EXPECT_EQ(checkPassword(NO_NUMBERS_PASSWORD, NO_NUMBERS_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneNumber);
    EXPECT_EQ(checkPassword(NO_SPECIAL_CHARS_PASSWORD, NO_SPECIAL_CHARS_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
    EXPECT_EQ(checkPassword(NO_UPPERCASE_PASSWORD, NO_UPPERCASE_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);

    EXPECT_EQ(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), ErrorCode::Ok);
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch); 
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "Ok");
}