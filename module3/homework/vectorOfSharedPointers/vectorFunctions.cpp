#include "vectorFunctions.hpp"

std::vector<std::shared_ptr<int>> generate(int count) {

//która wygeneruje wektor współdzielonych wskaźników na liczby od 0 do count

    std::vector<std::shared_ptr<int>> tempVector;

    if (count > 0) {

    tempVector.reserve(count);

    for (unsigned int i = 0; i < count; i++) {

    tempVector.emplace_back(std::make_shared<int>(i));

    }

    }

    return tempVector;

}


void print(std::vector<std::shared_ptr<int>> vecOfSharedPtr) {

//która wypisze wszystkie elementy ze wskaźników wektora

    for (const auto& element : vecOfSharedPtr) {

        std::cout << *(element) << " ";

    }

    std::cout << "\n";

}

void add10(std::vector<std::shared_ptr<int>> vecOfSharedPtr) {

//która przyjmie wektor i doda do każdej liczby 10

    for (auto& element : vecOfSharedPtr) {

        if (element != nullptr) {
        *element += 10;
        }
    }


}

void sub10(int * const ptrToIntValue) {

//która przyjmie stały wskaźnik na int i odejmie od tego elementu 10
    if (ptrToIntValue != nullptr) {
    *ptrToIntValue -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>> vecOfSharedPtr) {

//Która przyjmie wektor współdzielonych wskaźników i wywoła dla każdego elementu powyższe przeciążenie funkcji sub10()

    for (auto& element : vecOfSharedPtr) {

        sub10(element.get());

    }

    std::cout << "\n";


}

