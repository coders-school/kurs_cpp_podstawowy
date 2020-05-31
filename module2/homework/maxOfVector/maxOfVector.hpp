#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int> numbers) {
    int liczba; //liczba elementów w wektorze
    int liczba3; //największa wartość zwracana przez funkcję

    liczba = numbers.size();
    liczba3 = numbers.front();

    for (int liczba2 = 0 && liczba3; liczba2<liczba; liczba2++) {
        if(liczba3<numbers[liczba2]){
            liczba3 = numbers[liczba2];
        }

    }

return liczba3;
}
