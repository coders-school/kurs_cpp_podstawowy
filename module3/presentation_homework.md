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
* Zadanie 3 - MaxOfVector (4 punkty)
* Zadanie 4 - GenerateSequence (4 punkty)

#### Bonus za punktualność

Za dostarczenie każdego zadania przed 31.05.2020 (niedziela) do 23:59 dostaniesz 2 bonusowe punkty (razem 8 punkty za 4 zadania).

#### [Zadania w repo](https://github.com/coders-school/kurs_cpp_podstawowy/tree/master/module2/homework)

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

Zaimplementuj dwie funkcje. Obie mają liczyć n-tą liczbę [ciągu Fibonacciego](https://pl.wikipedia.org/wiki/Ciąg_Fibonacciego), ale na odmienne sposoby.

* iteracyjnie (z użyciem pętli)
* rekurencyjnie (funkcja ma wołać samą siebie)

Funkcje muszą mieć określone sygnatury:

```cpp
int fibonacci_iterative(int sequence);
int fibonacci_recursive(int sequence);
```

___
<!-- .slide: style="font-size: 0.55em" -->

## Dostarczenie zadań

1. Zrób fork repo [kurs_cpp_podstawowy](https://github.com/coders-school/kurs_cpp_podstawowy)
2. Ściągnij swój fork - `git clone https://github.com/YOURNICK/kurs_cpp_podstawowy.git`
3. Przejdź do katalogu kurs_cpp_podstawowy - `cd kurs_cpp_podstawowy`
4. Utwórz gałąź o nazwie `calculate` na rozwiązanie zadania calculate - `git checkout -b calculate`
5. Przejdź do katalogu module1/homework/calculate - `cd module1/homework/calculate`
6. Tutaj znajduje się szkielet programu, który musisz wypełnić. Szkielet programu zawiera już testy, które sprawdzą, czy Twoja implementacja jest poprawna. Zanim rozpoczniesz implementację wpisz następujące zaklęcia:

```bash
mkdir build   # tworzy katalog build
cd build      # przechodzi do katalogu build
cmake ..      # generuje system budowania wg przepisu z pliku ../CMakeLists.txt
make          # kompiluje
ctest -V      # odpala testy
```

7. Zaimplementuj funkcjonalność (najlepiej po kawałku, np. zacznij od samego dodawania)
8. Sprawdź, czy implementacja przechodzi testy - `make` (kompilacja) oraz `ctest -V` (uruchomienie testów)
9. Zrób commit z opisem działającej funkcjonalności - `git commit -am"adding works"`
10. Wróć do punktu 7 i zaimplementuj kolejny kawałek. Jeśli rozwiązanie przechodzi wszystkie testy przejdź do kolejnego punktu
11. Wypchnij zmiany do swojego forka - `git push origin calculate`
12. Wyklikaj Pull Request na GitHubie.
13. Poczekaj chwilę na raport Continuous Integration (CI), aby sprawdzić, czy rozwiązanie kompiluje się i przechodzi testy także na GitHubie.
14. Jeśli jest ✅ - brawo, rozwiązanie jest poprawne. Jeśli jest ❌ kliknij na niego i sprawdź opis błędu. Popraw go (punkty 7-11) i poczekaj na kolejny raport CI.

___

## Dostarczenie kolejnych zadań

Najpierw wróć na gałąź główną - `git checkout master` i postępuj od kroku 4 dla kolejnego zadania (stworzenie nowej gałęzi o innej nazwie)

Możesz zaobserwować, że przełączenie się na inną gałąź spowodowało, że nie masz rozwiązania pierwszego zadania. Spokojnie, jest ono po prostu na innej gałęzi. Możesz do niego wrócić przechodząc na gałąź tego zadania - `git checkout nazwa`.
