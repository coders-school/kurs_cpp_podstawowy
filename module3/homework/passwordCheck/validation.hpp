#pragma once
#include <iostream>
#include <memory>
#include <numeric>
#include <algorithm>
// TODO: I'm empty :) Put enum and function headers here.
// Don't forget the header guard
//
// Tworzysz moduł do sprawdzania reguł haseł, który otrzymuje dane z formularza kontaktowego z front-endu. Cały moduł to zestaw kilku funkcji. Ich deklaracje mają znaleźć się w pliku nagłówkowym validation.hpp, a implementacje w pliku źródłowym validation.cpp. Twoje zadania to:
/*
    Zdefiniuj w pliku nagłówkowym nowy typ ErrorCode z możliwymi wartościami dla błędów przy ustalaniu nowego hasła (1 punkt)
        Ok
        PasswordNeedsAtLeastNineCharacters
        PasswordNeedsAtLeastOneNumber
        PasswordNeedsAtLeastOneSpecialCharacter
        PasswordNeedsAtLeastOneUppercaseLetter
        PasswordsDoesNotMatch

Zadanie PasswordCheck cd.

    Napisz funkcję getErrorMessage(), która przyjmie zdefiniowany typ kodu błędu i zwróci stosowny komunikat jako napis. (1 punkt)
    Napisz funkcję doesPasswordsMatch(), która otrzyma dwa hasła i sprawdzi czy są identyczne. Powinna zwrócić odpowiednią wartość typu bool. (1 punkt)
    Napisz funkcję checkPasswordRules(), która przyjmie jedno hasło i losowo zwróci jeden z kodów PasswordNeedsAtLeast* lub Ok. (2 punkty)
    Napisz funkcję checkPassword(). Powinna ona przyjąć dwa hasła i używać funkcji doesPasswordsMatch() w celu określenia czy hasła się zgadzają. W przypadku gdy się nie zgadzają ma ona zwrócić kod PasswordsDoesNotMatch, a w przeciwnym przypadku powinna zwrócić kod błędu zwrócony przez wywołanie funkcji checkPasswordRules(). (2 punkty)
    Dla ambitnych (nieobowiązkowe) - zaimplementuj w funkcji checkPasswordRules() prawdziwą walidację pozostałych przypadków, które są podane jako kody błędów. Najlepiej, jeśli wykorzystasz funkcje z nagłówka oraz algorytm std::any_of. Dopisz/zmodyfikuj odpowiednie testy. (4 punkty)

Razem: 7 punktów (+4 dla ambitnych, +2 za dostarczenie przed 07.06.2020 23:59, +3 punkty/osobę za pracę w parze)
Zadanie PasswordCheck - Przykład użycia

int main() {
    std::string password;
    std::string repeatedPassword;
    std::cout << "Set new password: ";
    std::cin >> password;
    std::cout << "Repeat password: ";
    std::cin >> repeatedPassword;
    auto result = checkPassword(password, repeatedPassword);
    std::cout << getErrorMessage(result) << '\n';

    return 0;
}
*/

enum class ErrorCode{
       Ok,
       PasswordNeedsAtLeastNineCharacters,
       PasswordNeedsAtLeastOneNumber,
       PasswordNeedsAtLeastOneSpecialCharacter,
       PasswordNeedsAtLeastOneUppercaseLetter,
       PasswordsDoesNotMatch
};

std::string getErrorMessage(ErrorCode error);

bool doesPasswordsMatch(std::string first, std::string second);

ErrorCode checkPasswordRules(std::string password);

ErrorCode checkPassword(std::string first, std::string second);


