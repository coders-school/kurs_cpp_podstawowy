#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int liczba; //liczba elementów w wektorze
    int liczba3 = 0; //suma liczb zwracana przez funkcję
    liczba = numbers.size();

    for (int liczba2 = 0 && liczba3; liczba2<liczba; liczba2++) {

        if (numbers[liczba2]%2==0) {

            liczba3=numbers[liczba2]+liczba3;
        }
    }

return liczba3;
}
