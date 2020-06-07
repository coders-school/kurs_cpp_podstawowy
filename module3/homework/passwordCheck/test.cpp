#include "gtest/gtest.h"
#include "validation.hpp"

std::string EMPTY_PASSWORD = "";
std::string PROPER_PASSWORD = "abcABC123!@#";
std::string TOO_SHORT_PASSWORD = "12345678";
std::string WITHOUT_SPECIAL_CHAR = "AZWEasdfgrwfe12kzfdsm";
std::string ONLY_LOWER_CASE = "auipolk2sada1&%aos";
auto MIN_ALLOWED_ERROR_CODE = ErrorCode::Ok;
auto MAX_ALLOWED_ERROR_CODE = ErrorCode::PasswordsDoesNotMatch;

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

TEST(checkPasswordRulesTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPasswordRules(EMPTY_PASSWORD), MIN_ALLOWED_ERROR_CODE);  // greater or equal >=
    EXPECT_LE(checkPasswordRules(EMPTY_PASSWORD), MAX_ALLOWED_ERROR_CODE);  // less or equal <=
    EXPECT_GE(checkPasswordRules(TOO_SHORT_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(TOO_SHORT_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_EQ(checkPasswordRules(WITHOUT_SPECIAL_CHAR), ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter);
    EXPECT_EQ(checkPasswordRules(TOO_SHORT_PASSWORD), ErrorCode::PasswordNeedsAtLeastNineCharacters);
    EXPECT_EQ(checkPasswordRules(ONLY_LOWER_CASE), ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter);
}

TEST(checkPasswordTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);  // equal ==
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "OK");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters), "Password requires at least 9 characters");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber), "Password requires at least one number");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter), "Password requires at least special character");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter), "Password requires at least one uppercase letter");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordsDoesNotMatch), "Password does not match");
}