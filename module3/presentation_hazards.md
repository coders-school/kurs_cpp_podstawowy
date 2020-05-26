<!-- .slide: data-background="#111111" -->

# Podstawy C++

## Zagrożenia

### w stosowaniu referencji i wskaźników

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Puste wskaźniki

```cpp
int* a = nullptr;
std::cout << *a;
```

Dostęp do zmiennej wskazywanej przez pusty wskaźnik to niezdefiniowane zachowanie.
<!-- .element: class="fragment fade-in" -->

___

## Niezainicjalizowane wskaźniki

```cpp
int* a;
std::cout << *a;
```

Wskaźnik `a` zawiera tzw. śmieci.
Dostęp do obiektu wskazywanego przez taki wskaźnik to niezdefiniowane zachowanie.
<!-- .element: class="fragment fade-in" -->

___

## Odwołania do usuniętych zmiennych

Jak już dobrze wiemy, zmienne lokalne są usuwane po wyjściu z zakresu, w którym je utworzyliśmy.
Można już domyślać się, jakie problemy sprawią nam wskaźniki i referencje, gdy będą dalej istniały, a obiekt, do którego się odwołują już zostanie zniszczony.
Będzie to w najlepszym przypadku <span class="fragment highlight-red">„crash”</span>, w najgorszym <span class="fragment highlight-red">„undefined behaviour”</span>.

### Jak zapobiegać takim przypadkom?
<!-- .element: class="fragment fade-in" -->

Zawsze musimy zapewnić, aby czas życia zmiennej, był dłuższy niż czas życia jej wskaźnika, czy referencji.
<!-- .element: class="fragment fade-in" -->

___

## Usunięte zmienne - przykład

## TODO: Add line highlighting

```cpp []
int generateNewNumber();  // implementation not important
std::vector<int*> vec;

void createAndAddToVec(int amount) {
    for (int i = 0 ; i < amount ; ++i) {
        int new_value = generateNewNumber();
        vec.push_back(&i);
    }
    // local variable i does not exist here anymore
    // vec contains addresses to not existing local variables
}

int main() {
    createAndAddToVec(5);
    for (const auto& el : vec) {
        std::cout << *el << '\n';   // UB
    }
}
```

___

## Jak sobie poradzić z takim problemem?

Odpowiedzią może być dynamicznie alokowana pamięć.
<!-- .element: class="fragment fade-in" -->

Najprościej jest to osiągnąć używając biblioteki `#include <memory>`, która posiada `std::shared_ptr<T>`.
<!-- .element: class="fragment fade-in" -->

Wskaźnik ten nie bez powodu nazywany jest _inteligentnym_. Odpowiada on za zarządzanie dynamiczną pamięcią i sam zwalnia zasób, gdy już go nie potrzebujemy.
<!-- .element: class="fragment fade-in" -->

### Jak taki wskaźnik utworzyć?
<!-- .element: class="fragment fade-in" -->

```cpp
auto ptr = std::make_shared<int>(5);  // preferred
auto ptr = std::shared_ptr<int>(new int{5});
```
<!-- .element: class="fragment fade-in" -->

___

## Poprawiony listing

```cpp
int generateNewNumber();  // implementation not important
std::vector<std::shared_ptr<int>> vec; // previously: std::vector<int*> vec;

void createAndAddToVec(int amount) {
    for (int i = 0 ; i < amount ; ++i) {
        vec.push_back(std::make_shared<int>(i));
        // previously: vec.push_back(&i);

        // the same in 2 lines:
        // auto num = std::make_shared<int>(i);
        // vec.push_back(num);
    }
}

int main() {
    createAndAddToVec(5);
    for (const auto& el : vec) {
        std::cout << *el << '\n';
    }
}
```

___

## Inteligentne wskaźniki rozwiązaniem wszystkich problemów?

Teraz po utworzeniu inteligentnego wskaźnika, nie musimy się martwić o czas życia zmiennej.
Możemy spokojnie po wyjściu z funkcji wypisać te wartości.
<!-- .element: class="fragment fade-in" -->

Jeżeli funkcja potrzebuje przyjąć zwykły wskaźnik (ang. raw pointer), czyli np. `int* i` możemy to zrobić
używając funkcji `std::shared_ptr::get()` jak na przykładzie:
<!-- .element: class="fragment fade-in" -->

```cpp
void foo(int* num) {
    do_sth(num);
}
  
int main() {
    auto ptr = std::make_shared<int>(5);
    foo(ptr.get())
}
```
<!-- .element: class="fragment fade-in" -->

___

## Pułapka powraca

```cpp
void foo(int* num) {
    do_sth(num);
}
  
int main() {
    auto ptr = std::make_shared<int>(5);
    int* raw = ptr.get();
    ptr.reset();    // delete object, deallocate memory
    foo(raw);       // problem
}
```

Jeżeli wszystkie obiekty `shared_ptr<T>` odwołujące się do tej zmiennej zostaną usunięte, to zasób zostanie zwolniony.
<!-- .element: class="fragment fade-in" -->

Nasz zwykły wskaźnik, który pobraliśmy wcześniej za pomocą `get()`, będzie posiadał adres do nieistniejącego już zasobu.
<!-- .element: class="fragment fade-in" -->

Próba jego użycia spowodowuje niezdefiniowane zachowanie lub crash programu. Należy więc bardzo uważać na zwykłe wskaźniki.
<!-- .element: class="fragment fade-in" -->

___

## Wnioski

* <!-- .element: class="fragment fade-in" --> wskaźniki mogą nie wskazywać na nic (<code>nullptr</code>), referencje muszą wskazywać na jakiś wcześniej stworzony obiekt
* <!-- .element: class="fragment fade-in" --> wskaźniki i referencje mogą być niebezpieczne (częściej wskaźniki), jeśli są powiązane z nieistniejącymi już obiektami
  * <!-- .element: class="fragment fade-in" --> tzw. dangling pointers/references, wiszące wskaźniki/referencje
* <!-- .element: class="fragment fade-in" --> lepiej domyślnie nie używać zwykłych wskaźników (raw pointers)
* <!-- .element: class="fragment fade-in" --> lepiej stosować inteligentne wskaźniki
