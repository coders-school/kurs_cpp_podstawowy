<!-- .slide: data-background="#111111" -->

# Podstawy C++

## Referencje

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

Magiczny znaczek `&` oznacza referencję. Np -> int& num -> oznacza zmienną num, typu int&, czyli referencji na typ int.
No dobrze, ale czym jest referencja? Najprościej mówiąc, referencja odwołuje się do istniejącego obiektu.
Czyli jeżeli utworzymy obiekt `num` to poprzez referencje `int& reference = num` będziemy mogli się do niego bezpośrednio odwoływać.

Spójrzmy na fragment kodu.
```
  int number = 5;
  int& refer = number;

  std::cout << refer << '\n';   // 5
  std::cout << ++refer << "\n"; // 6
  std::cout << number << "\n";  // 6
```
Co zyskujemy w ten sposób? Nie musimy kopiować elementów. Wystarczy, że przekażemy referencje. W ten sposób możemy
swobodnie w wielu miejscach programu odczytywać wartość tej zmiennej, bez zbędnego jej kopiowania. 
Oczywiście referencja zajmuje 4 bajty w pamięci
zatem tworzenie referencji do typu int (4 bajty) nie zawsze ma sens, chyba, że chcemy zmodyfikować te element.
Przekazywanie argumentów przez referencje nabierze więcej sensu, kiedy poznamy już klasy i obiekty :).

Jak przekazać element przez referencje?
```
  void foo (int& num) {
    std::cout << num; // good
    num += 2; // good
  }
```
Gdy chcemy mieć pewność, ze nikt nie zmodyfikuje nam wartości (chcemy ja przekazać tylko do odczytu) dodajemy const
```
  void bar (const int& num) {
    std::cout << num; // good
    num += 2; // bad! num is const reference!
  }
```
Wywołanie funkcji to po prostu:
```
  int num = 5;
  foo(num);
  bar(num);
```
