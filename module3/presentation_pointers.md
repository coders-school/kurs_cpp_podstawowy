<!-- .slide: data-background="#111111" -->

# Podstawy C++

## Wskaźniki

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## *

Poza referencjami istnieją także wskaźniki. Wskaźniki działają podobnie jak referencje.
<!-- .element: class="fragment fade-in" -->

Wyobraźmy sobie, że planujemy wycieczkę na Majorkę. Wsiadamy do samolotu i lecimy.
Na miejscu okazuje się, ze zapomnieliśmy jaki jest adres hotelu :(
W celu znalezienia go musimy zadzwonić do biura podróży, poczekać na obsługę, wytłumaczyć całą zawiłą historię, aż w końcu po długim czasie otrzymujemy adres naszego hotelu.
Proces zdobycia tych informacji był dla nas czasochłonny.
<!-- .element: class="fragment fade-in" -->

Wyobraźmy sobie jednak, że uprzednio zapisaliśmy sobie w telefonie adres naszego hotelu. Aby przypomnieć sobie, gdzie on się znajdował wystarczy, że sprawdzimy telefon i już wiemy. Proces ten zajął nam dużo mniej czasu.
<!-- .element: class="fragment fade-in" -->

Podobnie jest w C++. Wskaźniki służą do wskazywania miejsca w pamięci, gdzie znajduje się pożądany przez nas obiekt.
Jeżeli funkcja przyjmuje wskaźnik, nie musi ona kopiować całej zawartości obiektu, (co jest czasochłonne), można dużo szybciej
wskazać gdzie ten obiekt już istnieje.
<!-- .element: class="fragment fade-in" -->

___

### Jak przekazać element przez wskaźnik?

```cpp
void foo (int* num) {
    std::cout << *num;  // good
    *num += 2;          // good
}
```
<!-- .element: class="fragment fade-in" -->

Gdy chcemy mieć pewność, że nikt nie zmodyfikuje nam wartości (chcemy ją przekazać tylko do odczytu) dodajemy `const`.
<!-- .element: class="fragment fade-in" -->

```cpp
void bar (int const* num) {
    std::cout << *num;  // good
    *num += 2;          // compilation error, num is const pointer
}
```
<!-- .element: class="fragment fade-in" -->

Wywołanie funkcji to:
<!-- .element: class="fragment fade-in" -->

```cpp
  int num = 5;
  foo(&num);
  bar(&num);
```
<!-- .element: class="fragment fade-in" -->

___

## Różnice między wskaźnikiem i referencją

Do referencji odwołujemy się tak samo jak do zwykłego obiektu, a aby uzyskać element wskazywany przez wskaźnik musimy dodać `*`.
Symbol `*` (operator dereferencji) oznacza obiekt wskazywany. Jeżeli nie damy `*` wypisany zostanie adres tego obiektu.
Ma to sens, ponieważ wskaźnik, wskazuje miejsce w pamięci, gdzie znajduje się obiekt.
<!-- .element: class="fragment fade-in" -->

Różnicę widać także, przy przekazywaniu argumentów do funkcji.
Dla referencji i zwyklej zmiennej postępujemy tak samo, natomiast dla wskaźnika musimy dodać `&`.
`&` oznacza w tym przypadku adres naszej zmiennej. Ma to również sens, ponieważ wskaźnik przechowuje adres obiektu, do którego chcemy się odwołać przez `*`.
<!-- .element: class="fragment fade-in" -->

___

## Różnice w kodzie

```cpp
void copy(int a) { a += 2; }
void ref(int& a) { a += 2; }
void ptr(int* a) ( *a += 2; )

void example() {
    int c = 10;
    int& r = a;
    int* p = &a;  // typically int* p = new int{10};
    copy(c);
    copy(r);
    copy(*p);
    ref(c);
    ref(r);
    ref(*p);
    ptr(&c);
    ptr(&r);
    ptr(p);
}
```

___

## Co oznacza `*` w kodzie?

```cpp
int a = 5 * 4;      // jako operacja arytmetyczna - mnożenie
int* b = &a;        // przy typie - wskaźnik na ten typ
int *c = &a;        // przy typie - wskaźnik na ten typ
std::cout << *b;    // przy zmiennej wskaźnikowej - dostęp do obiektu
int fun(int* wsk);  // w argumencie funkcji - przekazanie wskaźnika (adresu)
```
<!-- .element: class="fragment fade-in" -->

## Co oznacza `&` w kodzie?
<!-- .element: class="fragment fade-in" -->

```cpp
int a = 5 & 4;      // jako operacja arytmetyczna - suma bitowa
int& b = a;         // przy typie - referencja na ten typ
int &c = a;         // przy typie - referencja na ten typ
std::cout << &a;    // przy zmiennej - adres tej zmiennej w pamięci
int fun(int& ref);  // w argumencie funkcji - przekazanie adresu
```
<!-- .element: class="fragment fade-in" -->
