# 0 Krótkie przypomnienie, co już wiemy.

- Co zapamiętaliście z poprzednich zajęć?
- Co sprawiło największą trudność?
- Co najłatwiej było Wam zrozumieć?

# 1 Lista.

- Pytanie -> Jakie cechy miał std::vector?

Lista w przeciwieństwie do wektora jest porozrzucana po pamięci. Co czasami jest wygodne, gdyż możemy wykorzystać fragmenty pamięci,
które mogłyby, by być niedostępne dla wektora.

- Pytanie -> Jak elementy listy mogą wiedzieć o swoim wzajemnym istnieniu?

Każdy element listy przechowuje wskaźnik na element następny (lista jedno kierunkowa) lub następny i poprzedni (lista dwukierunkowa).

Podstawowe funkcję std::list:
  - front() i back() -> zwracają pierwszy i ostatni element listy,
  - begin() i end() -> zwracają iterator na pierwszy i ostatni element,
  - size() -> zwraca informacje o ilości elementów w liście,
  - empty() -> zwraca informacje czy lista jest pusta,
  - push_back() -> dodaje element na koniec listy,
  - push_front() *NOWOŚĆ* -> dodaje element na początek listy,
  - sort() *NOWOŚĆ* -> sortuje elementy listy (dla listy nie możemy korzystać ze zwykłego std::sort).

- Pytanie -> Jak dostać się do 10 elementu listy?

Ponieważ każdy element listy wie tylko o poprzednim i następnym elemencie, nie możemy tak łatwo dostać
się do 10 elementu listy.

Dostęp do pierwszego elementu możemy otrzymać przez `front()` lub `*begin()`
```
  int main() {
  std::list<int> list {1, 2, 3, 4, 5};
  std::cout << *list.begin();
  std::cout << list.front;
  }
```
Dostęp do 10 elementu możemy uzyskać przechodząc od 1 do 10.
```
  int main() {
  std::list<int> list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = list.begin();
  for (size_t i = 0 ; i < 10 ; ++i)
  {
  ++it; // jump to next element
  }
  std::cout << *it;
  }
```
Jak widać zajmuje to wiecej czasu, niż dostanie się do 10 elementu w std::vector<>.

-Pytanie: Kiedy zatem opłaca się używać std::list, a kiedy std::vector?

# 2 Mapa
Mapa to zbiór par klucz wartość. Przykładowo tworzymy sobie kolekcje ulubionych płyt i układamy je sobie w szafce.
Oczywiście płyt tych mamy ogromną liczbę i chcielibyśmy móc łatwo odnaleźć płytę, gdy będziemy jej poszukiwać.
W tym celu numerujemy sobie wszystkie płyty i zapisujemy sobie na kartce informacje, pod jakim numerem znajduje się
określony tytuł. W ten sposób tworzymy nic innego jak mapę.
```
  std::map<size_t, std::string> map {
  {1, "The Lord of the Rings: The Fellowship of the Ring"},
  {2, "The Lord of the Rings: The Two Towers"},
  {3, "The Lord of the Rings: The Return of the King"}
  };
```
Kluczem jest numer, natomiast wartością jest tytuł filmu.

Podstawowe funkjce std::map:
  - begin() i end() -> zwracają iterator na pierwszy i ostatni element,
  - size() -> zwraca informacje o ilości elementów w mapie,
  - empty() -> zwraca informacje czy mapa jest pusta,
  - operator[] -> zwraca element dla określonego klucza
  - insert() -> dodaje parę (klucz, wartość) do mapy o ile taka para jeszcze w niej nie występuje.

- Pytanie: Co się wydarzy, gdy zawołamy na wspomnianej mapie: `map[4] = "Harry Potter";`

Należy zapamiętać, że gdy przypisujemy cos do elementu mapy poprzez 'operator[]' to jeżeli istnieje już wartość
dla danego klucza to ją podmienimy. Natomiast, gdy nie istnieje wartość dla danego klucza, to utworzymy nową parę
klucz, wartość.
```
  #include <iostream>
  #include <map>
  #include <string>

  void Print(const std::map<size_t, std::string>& map) {
  for (const auto& pair : map) {
  std::cout << pair.first << " | " << pair.second << '\n';
  }
  }

  int main() {
  std::map<size_t, std::string> map {
  {1, "The Lord of the Rings: The Fellowship of the Ring"},
  {2, "The Lord of the Rings: The Two Towers"},
  {3, "The Lord of the Rings: The Return of the King"}
  };

  Print(map);
  std::cout << "\nAfter add new element\n";
  map[4] = "Harry Potter";
  Print(map);

  std::cout << "\nAfter modify element\n";
  map[4] = "Harry Potter and the Philosopher's Stone";
  Print(map);
  }
```
Wynik, jaki otrzymamy to:
```
  1 | The Lord of the Rings: The Fellowship of the Ring
  2 | The Lord of the Rings: The Two Towers
  3 | The Lord of the Rings: The Return of the King

  After add new element
  1 | The Lord of the Rings: The Fellowship of the Ring
  2 | The Lord of the Rings: The Two Towers
  3 | The Lord of the Rings: The Return of the King
  4 | Harry Potter

  After modify element
  1 | The Lord of the Rings: The Fellowship of the Ring
  2 | The Lord of the Rings: The Two Towers
  3 | The Lord of the Rings: The Return of the King
  4 | Harry Potter and the Philosopher's Stone
```

# 3 SHM — Symulator Handlu Morskiego

[Zdjęcie jakiegoś ładnego statku, może być galeon] w tym czasie omówię co będziemy rowzijać.

[Zdjęcia diagramu UML, który podeśle] krótkie omówienie niektórych zagadnień na przykładzie UML'a

# 4 Wprowadzenie do programowania obiektowego

- Pytanie: Czym jest obiekt?

Obiekt w C++ niczym się nie różni od rzeczywistego obiektu. W C++ możemy mieć obiekty takie jak:
  - Komputer,
  - Drukarka,
  - Ołówek,
  - Kalkulator etc.

- Pytanie: Czym może być klasa?

Tym razem klasa w C++ nieco różni się od rzeczywistej klasy :). W C++ klasa określa cechy obiektu:
  - jakie właściwości będzie miał ten obiekt,
  - jakie będzie miał metody działania.

  - Pytanie: jakie właściwości mógłby mieć obiekt komputer?
  - Pytanie: jakie metody mógłby mieć komputer?

```
  class Computer {
  Processor processor_;
  Drive drive_;
  Motherboard motherboard_;
  GraphicsCard graphics_card_;
  Memory memory_;

  void Run();
  void Restart();
  void Shutdown();
  };
```
Nic nie stoi na przeszkodzie, by jeden obiekt, składał się z innych obiektów. W ten sposób sprawiamy, że struktura naszego
kodu staje się bardziej zrozumiała.

Poza klasami istnieje jeszcze struktura. Jej podstawowa różnica polega na tym, że wszystkie elementy struktury
jej metody i zmienne są domyślnie publiczne. Natomiast w klasie są domyślnie prywatne.

Słowo `private` oznacza, że tylko wewnątrz klasy mamy dostęp do tych pól. Nie możemy się do nich odwoływać poza tą klasą.
Słowo `public` oznacza, że dostęp do danych ma każda klasa.

```
  class Computer {
  private:
  void Restart();
  };

  Computer computer;
  computer.Restart(); // Forbidden, Restart is private member
```
```
  class Computer {
  public:
  void Restart();
  };

  Computer computer;
  computer.Restart(); // Ok
```
Słowo `protected` oznacza, że tylko wewnątrz klasy mamy dostęp do danych. Dodatkowym wyjątkiem jest fakt, że klasy pochodne,
czyli takie, które dziedziczą po naszej klasie, również mają do nich dostęp.

Konstruktor klasy — Jest to przepis określający, jak ma wyglądać nasz klasa w chwili stworzenia. Do konstruktora możemy podać
wszelkie potrzebne dla nas informacje, np. rozmiar tablicy, datę zakupu etc.

```
  class Ship {
  public:
  Ship(const std::string& name, size_t capacity):
  name_(name), capacity_(capacity) {}

  private:
  std::string name_;
  const size_t capacity_;
  };
```
Klasa może mieć również konstruktor bezargumentowy `Ship()` który jest generowany automatycznie, jeżeli klasa
nie ma zdefiniowanego żadnego innego konstruktora.

Do inicjalizacji danych w konstruktorze możemy wykorzystać 'listę inicjalizacyjną' jest to nic innego jak ten fragment kodu:
`: name_(name), capacity_(capacity)`. Elementem listy inicjalizacyjnej może być nawet inny konstruktor (oczywiście naszej klasy).

```
  class Ship {
  public:
  Ship(const std::string& name, size_t capacity):
  name_(name), capacity_(capacity) {}
  Ship(const std::string& name, size_t capacity, size_t crew):
  Ship(name, capacity), { crew_ = crew; }

  private:
  std::string name_;
  const size_t capacity_;
  size_t crew_;
  };
```

Destruktor -> Jest to funkcja sprzątająca nasz klasę. Możemy ja wykorzystać, jeżeli chcemy wywołać konkretne
akcje podczas niszczenia obiektu. Np. Zarejestrowanie tego faktu w dzienniku itp.

# 4 Hermetyzacja, gettery i settery

Aby zabezpieczyć nasz obiekt, przez niepożądanymi modyfikacjami, możemy dokonać, tak zwanej hermetyzacji.
Polega ona na umieszczeniu wszystkich właściwości w sekcji prywatnej a ich modyfikacje umożliwiać przez
funkcję. Najprostszymi funkcjami umożliwiającymi modyfikacje są settery. Czyli funkcjam, która przypisuje daną
wartość konkretnej zmiennej np.: `void SetName(const std::string& name) {name_ = name;}`. Ponieważ dane są prywatne
ich odczyt dokonujemy przez gettery np. `std::string GetName() const { return name_ }`.
Oczywiście, nie zawsze musimy umożliwiać modyfikacje wszystkich zmiennych, tak samo, jak nie wszystkie zmienne
mogą mieć swoje gettery. Wybór zależy od programisty.

# 5 Pytania i wyjaśnienia
