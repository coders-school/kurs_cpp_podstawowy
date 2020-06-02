#include "gtest/gtest.h"
#include "validation.hpp"

std::string EMPTY_PASSWORD = "";
std::string PROPER_PASSWORD = "abcABC123!@#";
std::string TOO_SHORT_PASSWORD = "12345678";
std::string NO_DIGIT_IN_PASSWORD = "abcABC!@#";
std::string NO_SPECIAL_CHARACTER_IN_PASSWORD = "abcABC123";
std::string NO_UPPERCASE_CHARACTER_IN_PASSWORD = "abc123!@#";
auto MIN_ALLOWED_ERROR_CODE = ErrorCode::Ok;
auto MAX_ALLOWED_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

TEST(DoesPasswordsMatchTests, returnsTrueForIdenticalPasswords) {
    EXPECT_TRUE(doesPasswordsMatch(EMPTY_PASSWORD, EMPTY_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(PROPER_PASSWORD, PROPER_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(TOO_SHORT_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(NO_DIGIT_IN_PASSWORD, NO_DIGIT_IN_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(NO_SPECIAL_CHARACTER_IN_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD));
    EXPECT_TRUE(doesPasswordsMatch(NO_UPPERCASE_CHARACTER_IN_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD));
}

TEST(DoesPasswordsMatchTests, returnsFalseForDifferentPasswords) {
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, PROPER_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, NO_DIGIT_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(EMPTY_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, NO_DIGIT_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(PROPER_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(TOO_SHORT_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(TOO_SHORT_PASSWORD, NO_DIGIT_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(TOO_SHORT_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(TOO_SHORT_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_DIGIT_IN_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_DIGIT_IN_PASSWORD, PROPER_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_DIGIT_IN_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_DIGIT_IN_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_DIGIT_IN_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_SPECIAL_CHARACTER_IN_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_SPECIAL_CHARACTER_IN_PASSWORD, PROPER_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_SPECIAL_CHARACTER_IN_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_SPECIAL_CHARACTER_IN_PASSWORD, NO_DIGIT_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_SPECIAL_CHARACTER_IN_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_UPPERCASE_CHARACTER_IN_PASSWORD, EMPTY_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_UPPERCASE_CHARACTER_IN_PASSWORD, PROPER_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_UPPERCASE_CHARACTER_IN_PASSWORD, TOO_SHORT_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_UPPERCASE_CHARACTER_IN_PASSWORD, NO_DIGIT_IN_PASSWORD));
    EXPECT_FALSE(doesPasswordsMatch(NO_UPPERCASE_CHARACTER_IN_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD));
}

TEST(checkPasswordRulesTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPasswordRules(EMPTY_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(EMPTY_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(TOO_SHORT_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(TOO_SHORT_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(PROPER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(NO_DIGIT_IN_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(NO_DIGIT_IN_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(NO_SPECIAL_CHARACTER_IN_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(NO_SPECIAL_CHARACTER_IN_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_GE(checkPasswordRules(NO_UPPERCASE_CHARACTER_IN_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPasswordRules(NO_UPPERCASE_CHARACTER_IN_PASSWORD), MAX_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, NO_DIGIT_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_DIGIT_IN_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_SPECIAL_CHARACTER_IN_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_UPPERCASE_CHARACTER_IN_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, NO_DIGIT_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_DIGIT_IN_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_SPECIAL_CHARACTER_IN_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_UPPERCASE_CHARACTER_IN_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, NO_DIGIT_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_DIGIT_IN_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_SPECIAL_CHARACTER_IN_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_UPPERCASE_CHARACTER_IN_PASSWORD, TOO_SHORT_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_DIGIT_IN_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_SPECIAL_CHARACTER_IN_PASSWORD, NO_DIGIT_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_DIGIT_IN_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_UPPERCASE_CHARACTER_IN_PASSWORD, NO_DIGIT_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_SPECIAL_CHARACTER_IN_PASSWORD, NO_UPPERCASE_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(NO_UPPERCASE_CHARACTER_IN_PASSWORD, NO_SPECIAL_CHARACTER_IN_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "OK");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters), "Password Needs At Least Nine Characters");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber), "Password Needs At Least One Number");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter), "Password Needs At Least One Special Character");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter), "Password Needs At Least One Uppercase Letter");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordsDoesNotMatch), "Passwords Does Not Match");
}
