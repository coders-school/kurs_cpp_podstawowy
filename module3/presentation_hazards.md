<!-- .slide: data-background="#111111" -->

# Podstawy C++

## Zagrożenia

### w stosowaniu referencji i wskaźników

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

Jak już dobrze wiemy, zmienne lokalne są usuwane po wyjściu z zakresu, w którym je utworzyliśmy.
Można już domyślać się, jakie problemy sprawią nam wskaźniki i referencje, gdy będą dalej istniały
a obiekt, do którego się odwołują już zostanie zniszczony. Bedzie to w najlepszym wypadku „crash”, w najgorszym „undefined behaviour”.
Jak zapobiegać takim przypadkom? Zawsze musimy zapewnić, aby czas życia zmiennej, był dłuższy niż czas życia jej wskaźnika, czy referencji.

Błędny Przykład:

```
  std::vector<int*> vec;

  void CreateAndAddToVec(int amount) {
    for (int i = 0 ; i < amount ; ++i) {
      int new_value = generateNewNumber();
      vec.push_back(&i);
    }
  }

  int main() {
    CreateAndAddToVec(5);
    for (const auto& el : vec) {
      std::cout << *el << '\n';
    }
  }

```
Jak sobie poradzić z takim problemem? Odpowiedzią jest dynamicznie alokowana pamięć.
Najprościej jest to osiągnąć używając biblioteki `#include <memory>`, która posiada `std::shared_ptr`.
Wskaźnik ten nie jest bez powodu nazywany `inteligentnym`. Odpowiada od na alokacje dynamicznej pamięci,
która nie jest usuwana po wyjściu z zasięgu oraz sam zwalnia zasób, gdy już go nie potrzebujemy.
Jak taki wskaźnik utworzyć? `auto ptr = std::make_shared<int>(5);`
Przyjrzyjmy się teraz poprawionemu listingowi:
```
  std::vector<std::shared_ptr<int>> vec;

  void CreateAndAddToVec(int amount) {
    for (int i = 0 ; i < amount ; ++i) {
      vec.push_back(std::make_shared<int>(i));
      // lub w 2 linijkach
      // auto num = std::make_shared<int>(i);
      // vec.push_back(num);
    }
  }

  int main() {
    CreateAndAddToVec(5);
    for (const auto& el : vec) {
      std::cout << *el << '\n';
    }
}
```
Teraz po utworzeniu inteligentnego wskaźnika, nie musimy się martwic o czas życia zmiennej. Możemy spokojnie
po wyjściu z funkcji wypisać te wartości.

Jeżeli funkcja potrzebuje przyjąć surowy wskaźnik (ang. raw pointer), czyli np. `int* i` możemy to zrobić
używając funkcji `std::shared_ptr::get()` jak na przykładzie:
```
  void foo(int* num) {
    do_sth(num);
  }
  
  int main() {
    auto num = std::make_shared<int>(5);
    foo(num.get())
  }
```

Jednak pułapka tutaj znowu powraca. Jeżeli wszystkie obiekty shard_ptr odwołujące się do tej zmiennej zostaną usunięte.
To zasób zostanie zwolniony. Zatem nasz surowy wskaźnik będzie posiadał adres do nieistniejącego już zasobu, co spowodowuje
udifined behaviour lub crash programu.
