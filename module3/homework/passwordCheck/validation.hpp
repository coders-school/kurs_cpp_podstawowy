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

std::string getErrorMessage(ErrorCode);

bool doesPasswordsMatch(std::string, std::string);