<!-- .slide: data-background="#111111" -->

# Podstawy C++

## Podsumowanie

<a href="https://coders.school">
    <img width="500px" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Co pamiętasz z dzisiaj?

### Napisz na czacie jak najwięcej haseł
<!-- .element: class="fragment fade-in" -->

1. <!-- .element: class="fragment fade-in" --> STL - co to?
2. <!-- .element: class="fragment fade-in" --> <code>std::vector</code>
3. <!-- .element: class="fragment fade-in" --> Pętla <code>for</code> po kolekcji
4. <!-- .element: class="fragment fade-in" --> <code>std::string</code>
5. <!-- .element: class="fragment fade-in" --> <code>std::list</code>
6. <!-- .element: class="fragment fade-in" --> <code>std::map</code>

___
<!-- .slide: style="font-size: 0.8em" -->

## Praca domowa

### Post-work

* Jeśli nie wiesz czym jest `operator%` to się dowiedz. Przyda się do pracy domowej :)
* Zadanie 1 - AddEven (4 punkty)
* Zadanie 2 - NWD (LCM) i NWW (GCD) (6 punktów)
* Zadanie 3 - MaxOfVector (5 punktów)
* Zadanie 4 - GenerateSequence (5 punktów)

#### Bonus za punktualność

Za dostarczenie każdego zadania przed 31.05.2020 (niedziela) do 23:59 dostaniesz 2 bonusowe punkty (razem 8 punktów za 4 zadania).

#### [Zadania w repo](https://github.com/coders-school/kurs_cpp_podstawowy/tree/module2/module2/homework)

___

### Pre-work

* Przypomnij sobie informacje o wskaźnikach np z [wideo pana Zelenta](https://www.youtube.com/watch?v=0DQl74alJzw)
* [Poczytaj o `enum`ach](http://cpp0x.pl/kursy/Kurs-C++/Typ-wyliczeniowy-enum/318)
* Zainteresuj się tematem smart pointerów i poszukać informacji czym jest `std::shared_ptr` i `std::unique_ptr`
* Możesz przyjrzeć się plikom z testami w zadaniach domowych i spróbować dopisać własne przypadki testowe

___

## Zadanie 1 - AddEven

Napisz funkcję, która przyjmie `std::vector<int>` oraz zwróci sumę wszystkich jego parzystych elementów.

Deklaracja - `int addEven(const std::vector<int>& numbers)`

Jeśli nie wiesz, co funkcja powinna zwracać w niektórych przypadkach to zapoznaj się z testami.

### Przykład użycia

```cpp
std::vector<int> vec{1, 2, 3, 4, 5};
auto result = addEven(vec);  // result = 6;
```

___

## Zadanie 2 - NWD (LCM) i NWW (GCD)

Zaimplementuj dwie funkcje - NWD, która ma liczyć Największy Wspólny Dzielnik i NWW, która ma liczyć Najmniejszą Wspólną Wielokrotność 2 liczb.
Uważaj na nietypowe przypadki, takie jak 0 lub liczby ujemne :)

### Przykład użycia

```cpp
std::cout << "NWW(255, 15) = " << NWW(255, 15) << "\n";
std::cout << "NWD(255, 15) = " << NWD(255, 15) << "\n";
```

___

## Zadanie 3 - MaxOfVector

Napisz funkcję, która przyjmuje `std::vector<int>` i zwraca największy element tego wektora.

### Przykład użycia

```cpp
std::vector<int> numbers = {6, 78, 12, 54, -11, 0};
auto result = maxOfVector(numbers);  // result = 78
```

___

## Zadanie 4 - GenerateSequence

Napisz funkcję, która przyjmuje 2 argumenty:

* `int count`
* `int step`

oraz zwraca `std::vector<int>` posiadający `count` elementów i każdy z nich jest większy od poprzedniego o `step`. Pierwszy ma wynosić tyle, ile `step`.

### Przykład użycia

```cpp
auto result = generateSequence(5, 3);  // result = {3, 6, 9, 12, 15}
```

___
<!-- .slide: style="font-size: 0.6em" -->

## Dostarczenie zadań (różnice w stosunku do lekcji Podstawy #1)

1. Już masz fork repo [kurs_cpp_podstawowy](https://github.com/coders-school/kurs_cpp_podstawowy), nie da się ponownie zrobić forka
2. Masz już ściągnięte swoje repo
3. Przejdź do katalogu repo - `cd kurs_cpp_podstawowy`
4. Dodaj nowe repozytorium zdalne - `git remote add coders https://github.com/coders-school/kurs_cpp_podstawowy.git`
5. Zaktualizuj repozytorium z nowo dodanego adresu `git fetch coders`
6. Przełącz się na branch module2 `git checkout module2`
7. Możesz nowo ściągniętego brancha wysłać też na swoje repo na GH `git push origin module2`
8. Postępuj tak samo jak przy poprzednich zadaniach, czyli najpierw utwórz oddzielną gałąź na nowe zadanie - `git checkout -b add_even`
9. Zaimplementuj rozwiązanie, robiąc dużo malutkich commitów.
10. Wysyłając zmiany na swojego GitHuba używaj komendy `git push origin add_even`
11. Przy zgłoszeniu Pull Requesta wyklikaj, że chcesz go dostarczyć do `coders-school/kurs_cpp_podstawowy` branch `module2`

## Dostarczenie kolejnych zadań

1. Najpierw wróć na gałąź module2 - `git checkout module2`
2. Stamtąd utwórz nową gałąź na swoje kolejne zadanie `git checkout -b nww_nwd` i dalej tak samo :)
