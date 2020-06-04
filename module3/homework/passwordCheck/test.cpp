#include "gtest/gtest.h"
#include "validation.hpp"

std::string EMPTY_PASSWORD = "";
std::string PROPER_PASSWORD = "abcABC123!@#";
std::string TOO_SHORT_PASSWORD = "12345678";
std::string PASSWORD_WITHOUT_DIGITS = "abcDEF!@#GhI";
std::string PASSWORD_WITHOUT_SPECIAL_CHARACTERS = "abcDEF0123GhI";
std::string PASSWORD_WITHOUT_UPPER_CHARACTERS = "abc#de01fg%$23";
auto MIN_ALLOWED_ERROR_CODE = ErrorCode::Ok;
auto MAX_ALLOWED_ERROR_CODE = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
auto ERROR_CODE_TOO_SHORT = ErrorCode::PasswordNeedsAtLeastNineCharacters;
auto ERROR_CODE_NO_DIGITS = ErrorCode::PasswordNeedsAtLeastOneNumber;
auto ERROR_CODE_NO_SPECIAL_CHARACTERS = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
auto ERROR_CODE_NO_UPPER_CHARACTERS = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;

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

TEST(checkPasswordRulesTests, returnsPropersValuesForDiferentsPasswords) {
    EXPECT_EQ(checkPasswordRules(EMPTY_PASSWORD), ERROR_CODE_TOO_SHORT);
    EXPECT_EQ(checkPasswordRules(TOO_SHORT_PASSWORD), ERROR_CODE_TOO_SHORT);
    EXPECT_EQ(checkPasswordRules(PASSWORD_WITHOUT_DIGITS), ERROR_CODE_NO_DIGITS);
    EXPECT_EQ(checkPasswordRules(PASSWORD_WITHOUT_SPECIAL_CHARACTERS), ERROR_CODE_NO_SPECIAL_CHARACTERS);
    EXPECT_EQ(checkPasswordRules(PASSWORD_WITHOUT_UPPER_CHARACTERS), ERROR_CODE_NO_UPPER_CHARACTERS);
}

TEST(checkPasswordTests, returnsValuesBetweenOkAndPasswordNeedsAtLeastOneUppercaseLetter) {
    EXPECT_GE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MIN_ALLOWED_ERROR_CODE);
    EXPECT_LE(checkPassword(PROPER_PASSWORD, PROPER_PASSWORD), MAX_ALLOWED_ERROR_CODE);
}

TEST(checkPasswordTests, returnsPasswordsDoesNotMatchForDifferentPasswords) {
    EXPECT_EQ(checkPassword(PROPER_PASSWORD, EMPTY_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(EMPTY_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch);
    EXPECT_EQ(checkPassword(TOO_SHORT_PASSWORD, PROPER_PASSWORD), ErrorCode::PasswordsDoesNotMatch); 
}

TEST(getErrorMessageTests, returnsErrorCodeAsString) {
    EXPECT_EQ(getErrorMessage(ErrorCode::Ok), "OK");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastNineCharacters), "Password is too short");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneNumber), "Password need to contain at least one digit");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter), "Password need to contain at least one special character (like: [#],[%],[,],[$],[/]");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter), "Password need to contain at least one uppercase letter");
    EXPECT_EQ(getErrorMessage(ErrorCode::PasswordsDoesNotMatch), "Passwords do not match");
}
