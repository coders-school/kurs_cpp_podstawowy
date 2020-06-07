#include "gtest/gtest.h"
#include "validation.hpp"

std::string EMPTY_PASSWORD = "";
std::string PROPER_PASSWORD = "abcABC123!@#";
std::string TOO_SHORT_PASSWORD = "12345678";
std::string NO_UPPERCASE_PASSWORD = "abcabc123!@#";
std::string NO_SPECIAL_CHAR_PASSWORD = "abcABC123";
std::string NO_NUMBER_PASSWORD = "abcABC!@#";
auto MIN_ALLOWED_ERROR_CODE = ErrorCode::Ok;
auto LESS_THAN_NINE_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastNineCharacters;
auto NO_NUMBER_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneNumber;
auto NO_SPECIAL_CHARACTER_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
auto MAX_ALLOWED_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

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
    EXPECT_EQ(checkPasswordRules(NO_UPPERCASE_PASSWORD), MAX_ALLOWED_ERROR_CODE);
    EXPECT_EQ(checkPasswordRules(NO_SPECIAL_CHAR_PASSWORD), NO_SPECIAL_CHARACTER_ERROR_CODE);
    EXPECT_EQ(checkPasswordRules(NO_NUMBER_PASSWORD), NO_NUMBER_ERROR_CODE);
    EXPECT_EQ(checkPasswordRules(TOO_SHORT_PASSWORD), LESS_THAN_NINE_ERROR_CODE);
    EXPECT_EQ(checkPasswordRules(PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch); // equal ==
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch); 
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "OK");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters), "Password needs at least nine characters.");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber), "Password needs at least one number.");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter), "Password needs at least one special character.");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter), "Password needs at least one uppercase letter.");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordsDoesNotMatch), "Password does not match.");
}

