#include "gtest/gtest.h"
#include "validation.hpp"

std::string EMPTY_PASSWORD = "";
std::string PROPER_PASSWORD = "abcABC123!@#";
std::string TOO_SHORT_PASSWORD = "12345678";
std::string NO_NUMBER_PASSWORD = "QWERTYUIOP";
std::string NO_SPECIAL_CHAR_PASSWORD = "1122AABB";
std::string SPACE_IS_NOT_SPECIAL = "1122 AABB";
std::string NO_UPPERCASE_PASSWORD = "1234567890_!@##asdfg"


TEST(DoesPasswordsMatchTests, returnsTrueForIdenticalPasswords) {
    EXPECT_TRUE(doesPasswordsMatch(EMPTY_PASSWORD, EMPTY_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(PROPER_PASSWORD, PROPER_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch("abc def", "abc def"));
}

TEST(DoesPasswordsMatchTests, returnsFalseForDifferentPasswords) {
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, PROPER_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch("abc def", "abc"));
    EXPECT_FALSE(doesPasswordsMatch("abc", "ABc"));
    EXPECT_FALSE(doesPasswordsMatch(" ", "  "));
}

TEST(checkPasswordRulesTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_FALSE(checkPasswordRules(EMPTY_PASSWORD), ErrorCode::Ok);
    EXPECT_TRUE(checkPasswordRules(EMPTY_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_FALSE(checkPasswordRules(TOO_SHORT_PASSWORD), ErrorCode::Ok);
    EXPECT_TRUE(checkPasswordRules(TOO_SHORT_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_FALSE(checkPasswordRules(NO_NUMBER_PASSWORD), ErrorCode::Ok);
    EXPECT_TRUE(checkPasswordRules(NO_NUMBER_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneNumber);
    EXPECT_FALSE(checkPasswordRules(NO_SPECIAL_CHAR_PASSWORD), ErrorCode::Ok);
    EXPECT_TRUE(checkPasswordRules(NO_SPECIAL_CHAR_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
    EXPECT_FALSE(checkPasswordRules(SPACE_IS_NOT_SPECIAL), ErrorCode::Ok);
    EXPECT_TRUE(checkPasswordRules(SPACE_IS_NOT_SPECIAL), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
    EXPECT_FALSE(checkPasswordRules(NO_UPPERCASE_PASSWORD, ErrorCode::Ok);
    EXPECT_TRUE(checkPasswordRules(NO_UPPERCASE_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);
    EXPECT_TRUE(checkPasswordRules(PROPER_PASSWORD), ErrorCode::Ok);
}

TEST(checkPasswordTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_TRUE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), ErrorCode::Ok);
    EXPECT_TRUE(checkPassword(EMPTY_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_TRUE(checkPassword(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_TRUE(checkPassword(NO_NUMBER_PASSWORD, NO_NUMBER_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneNumber);
    EXPECT_TRUE(checkPassword(NO_SPECIAL_CHAR_PASSWORD, NO_SPECIAL_CHAR_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
    EXPECT_TRUE(checkPassword(SPACE_IS_NOT_SPECIAL, SPACE_IS_NOT_SPECIAL), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
    EXPECT_TRUE(checkPassword(NO_UPPERCASE_PASSWORD, NO_UPPERCASE_PASSWORD), ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch); 
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "OK");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordsDoesNotMatch), "Error, password does not match!");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters), "Error, Password need at least 9 characters!");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber), "Error, Password need at least 1 number!";
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter), "Error, Password need at least one special character!"));
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:), "Error, Password need at least uppercase letter!");
}
