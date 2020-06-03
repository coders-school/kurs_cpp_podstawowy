// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard

enum ErrorCode {
    Ok,
    PasswordNeedsAtLeastNineCharacters,
    PasswordNeedsAtLeastOneNumber,
    PasswordNeedsAtLeastOneSpecialCharacter,
    PasswordNeedsAtLeastOneUppercaseLetter,
    PasswordsDoesNotMatch
}

std::string
getErrorMessage(ErrorCode code);

bool doesPasswordsMatch(std::string password1, std::string password2);

ErrorCode checkPasswordRules(std::string password);
