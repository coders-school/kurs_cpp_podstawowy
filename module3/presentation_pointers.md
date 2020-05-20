<!-- .slide: data-background="#111111" -->

# Podstawy C++

## Wskaźniki

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

Po za referencja istnieją także wskaźnik. Wskaźniki działają podobnie.
Wyobraźmy sobie, że planujemy wycieczkę na Majorkę. Pakujemy do walizki wszystkie potrzebne ciuchy, ładowarkę do telefonu,
laptopa ect. Wsiadamy do samolotu i lecimy. Na miejscu okazuje się, ze zapomnieliśmy jaki jest adres hotelu :(
W celu znalezienia go, musimy zadzwonić do biura podróży, poczekać na obsługę, następnie wytłumaczyć cała zawiłą historie aż 
w końcu po długim czasie otrzymujemy adres naszego hotelu. Proces zdobycia tych informacji był dla nas czasochłonny.
Wyobraźmy sobie jednak, że uprzednio zapisaliśmy sobie w telefonie adres naszego hotelu. Aby przypomnieć sobie, gdzie on się znajdował
wystarczy, że sprawdziliśmy sobie notatnik i już wiemy. Proces ten zajął nam dużo mniej czasu.
Podobnie jest w C++. Wskaźniki służą do wskazywania miejsca w pamięci, gdzie znajduje się pożądany przez nas obiekt.
Jeżeli funkcja przyjmuje wskaźnik, nie musi ona kopiować całej zawartości obiektu, (co jest czasochłonne), można dużo szybciej
wskazać gdzie ten obiekt już istnieje.

Jak przekazać element przez wskaźnik?
```
  void foo (int* num) {
    std::cout << *num; // good
    *num += 2; // good
  }
```
Gdy chcemy mieć pewność, ze nikt nie zmodyfikuje nam wartości (chcemy ja przekazać tylko do odczytu) dodajemy const
```
  void bar (int const* num) {
    std::cout << num; // good
    num += 2; // bad! num is const pointer!
  }
```
Wywołanie funkcji to:
```
  int num = 5;
  foo(&num);
  bar(&num);
```
Możemy zauważyć pewne rozbieżności pomiędzy referencja a wskaźnikiem. Do referencji odwołujemy się tak samo jak do zwykłego obiektu
a aby uzyskać element wskazywany przez wskaźnik musimy dodać `*`. Symbol ten oznacza obiekt wskazywany. Jeżeli nie damy `*` wypisany
zostanie adres tego obiektu. Ma to sens, ponieważ wskaźnik, wskazuje miejsce w pamięci, gdzie znajduje się obiekt.

Różnicę widać także, przy przekazywaniu argumentów do funkcji. Dla referencji i zwyklej zmiennej postępujemy tak samo, natomiast dla
wskaźnika musimy dodać `&`. `&` -> Oznacza w tym przypadku adres naszej zmiennej. Ma to również sens, ponieważ wskaźnik przechowuje 
adres obiektu, do którego chcemy się odwołać przez `*`.
