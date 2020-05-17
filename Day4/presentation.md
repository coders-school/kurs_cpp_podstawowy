# 0 Krótkie przypomnienie, co już wiemy.

- Co zapamiętaliście z poprzednich zajęć?
- Co sprawiło największą trudność?
- Co najłatwiej było Wam zrozumieć?

# 1 Omówienie problemów, przykładowe rozwiązania.

Zadanie:

(Pokazuje bardziej zaawansowane implementacje, ale tłumacze co jest ważne na ten moment).

Cargo.h
```
 bool operator==(const Cargo& cargo) const;
```

Cargo.cc
```
bool Cargo::operator==(const Cargo& cargo) const {
	return Cargo.GetBasePrice() == base_price_
		&& Cargo.GetName() == name_;
}
```

Zadanie2:
Cargo.h
```
  std::string GetName() const;
	size_t GetAmount() const;
	size_t GetBasePrice() const;
```
Cargo.cc
```
	std::string Cargo::GetName() const { return name_; }
	size_t Cargo::GetAmount() const { return amount_; }
	size_t Cargo::GetBasePrice() const { return base_price_; }
```

Zadanie3

Island.h
```
#ifndef ISLAND_H
#define ISLAND_H

#include <memory>
#include <iostream>

#include "Store.h"

class Time;

// Class describes position of island and available store.
class Island {
public:
	class Coordinates {
	public:
		Coordinates() = default;
		Coordinates(size_t pos_x, size_t pos_y) :
			pos_x_(pos_x), pos_y_(pos_y) {}

		bool operator==(const Coordinates& lhs) const { 
			return this->pos_x_ == lhs.pos_x_ && this->pos_y_ == lhs.pos_y_; 
		}
    
	private:
		const size_t pos_x_{ 0 };
		const size_t pos_y_{ 0 };
	};

	Island() {}
  Island(size_t pos_x, size_t pos_y, Time* time);
	Coordinates GetCoordinates() const { return position_; }
	Store* GetStore() const { return store_.get(); }

private:
    std::unique_ptr<Store> store_;
    Coordinates position_;
};
```
Island.cc
```
#include "Island.h"

#include "GTime.h"

Island::Island(size_t pos_x, size_t pos_y, Time* time): 
	position_(Coordinates(pos_x, pos_y)),
	store_(std::make_unique<Store>(time)) {
}
```

Zadanie4, Zadnaie5 i Zadanie6
Map.h
```
#ifndef MAP_H
#define MAP_H

#include <vector>

#include "Island.h"

class Time;

// Class responsible for generation map which will be used to travel.
class Map {
public:
	Map(Time* time);
  void Travel(Island* destination);
	Island* GetIsland(const Island::Coordinates& coordinate);
	Island* GetCurrentPosition() const { return current_position_; }
	friend std::ostream& operator<<(std::ostream& out, const Map& map);

private:
    Island* current_position_;
    std::vector<Island> islands_;
};

#endif // MAP_H
```
Map.cc
```
#include "Map.h"

#include <algorithm>
#include <random>

#include "GTime.h" 

constexpr size_t kIslandNum = 10;
constexpr size_t kWidth = 50;
constexpr size_t kHeight = 50;

Map::Map(Time* time) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> width_gen(0, kWidth);
	std::uniform_int_distribution<> height_gen(0, kHeight);
	std::vector<Island> islands(kIslandNum);
	std::vector<std::pair<size_t, size_t>> used_position;

	// Generate map
	for (size_t i = 0; i < kIslandNum; ++i) {
		while (true) {
			size_t x = width_gen(gen);
			size_t y = height_gen(gen);
			if (std::find_if(begin(used_position), end(used_position),
				[x, y](const auto& pos){
					return pos.first == x && pos.second == y;
				}) == std::end(used_position)) {
				used_position.push_back({ x, y });
				islands_.push_back(Island(x, y, time));
				break;
			}
		}
	}

	current_position_ = &islands_.front();
}

Island* Map::GetIsland(const Island::Coordinates& coordinate) {
	auto island = std::find_if(std::begin(islands_), std::end(islands_), 
		[&coordinate](const Island& island) {
			return coordinate == island.GetCoordinates();
		});
	return island != std::end(islands_) ? &*island : nullptr;
}

void Map::Travel(Island* destination) {
	current_position_ = destination;
}
```

Zadanie7 i Zadanie8:
```
#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "Cargo.h"
#include "Ship.h"

class Time;

// Class is responsible for every action made by player
class Player {
public:
	Player(size_t money, Time* time);
	virtual ~Player() = default;
	
	virtual size_t GetAvailableSpace() const;
  virtual size_t GetMoney() const { return money_; }
	virtual size_t GetSpeed() const;
	virtual Cargo* GetCargo(size_t index) const;
	
private:
  std::unique_ptr<Ship> ship_;
  size_t money_;
	size_t available_space_;
};

#endif // PLAYER_H
```
Player.cc
```
#include "Player.h"

#include "Cargo.h"
#include "Ship.h"
#include "GTime.h"

constexpr size_t kCapacity = 100;
constexpr size_t kCrew = 50;
constexpr size_t kSpeed = 10;
constexpr char kName[] = "BLACK WIDOW";
constexpr size_t kId= 10;

Player::Player(size_t money, Time* time): ship_(std::make_unique<Ship>(
		kCapacity, kCrew, kSpeed, kName, kId, time, this)),
	money_(money),
	available_space_(kCapacity) {
}

size_t Player::GetSpeed() const {
	return ship_->GetSpeed();
}

Cargo* Player::GetCargo(size_t index) const {
	return ship_->GetCargo(index);
}

size_t Player::GetAvailableSpace() const {
  available_space_ = 0;
  for (const auto cargo : ship_->GetCargos()) {
    available_space_ += cargo->GetAmount();
  }
  
  return available_space_;
}
```

# 2 Wprowadzenie do dziedziczenia:

Podczas implementacji klas, często możemy zauważyć, że część cech składowych klasy można wykorzystać także w innych klasach.
Weźmy pod lupę klasę Komputer. Jeżeli chcielibyśmy utworzyć klasy: laptop, PC, tablet. Część metod oraz składowych klasy musielibyśmy niepotrzebnie powielić.

```
Class Computer {
public:
  void TurnOn();
  void PowerOff();
  void Restart();
  
private:
  Processor processor_;
  Drive drive_;
  Motherboard motherboard_;
  GraphicsCard graphics_card_;
  Memory memory_;
}
```
```
Class Laptop {
public:
  void TurnOn();
  void PowerOff();
  void Restart();
  void Display();
  void GetUserInput();
  
private:
  Processor processor_;
  Drive drive_;
  Motherboard motherboard_;
  GraphicsCard graphics_card_;
  Memory memory_;
  Screen screen_;
  Keyboard keyboard_;
}
```
```
Class Tablet {
public:
  void TurnOn();
  void PowerOff();
  void Restart();
  void Display();
  void GetUserInput();
  
private:
  Processor processor_;
  Drive drive_;
  Motherboard motherboard_;
  GraphicsCard graphics_card_;
  Memory memory_;
  Screen screen_;
  Keyboard keyboard_;
}
```

- Pytanie: Jak uprościć strukturę naszego programu?

```
Class Computer {
public:
  void TurnOn();
  void PowerOff();
  void Restart();
  
protected:
  Processor processor_;
  Drive drive_;
  Motherboard motherboard_;
  GraphicsCard graphics_card_;
  Memory memory_;
}

class Laptop : public Computer {
public:
  void Display();
  void GetUserInput();
  
private:
  Screen screen_;
  Keyboard keyboard_;
}

class Tablet : public Computer {
public:
  void Display();
  void GetUserInput();
  
private:
  Screen screen_;
}
```


Klasa, po której dziedziczymy, nazywają się klasą bazową. Klasy, które dziedziczą, nazywa się klasami pochodnymi. Inaczej klasa, po której dziedziczymy to rodzic (parent class). Klasa, która dziedziczy to dziecko (child class).

- Pytanie: Co z metodami klasy Laptop i Tablet, czy można wydzielić kolejną klasę?
```
  void Display();
  void GetUserInput();
```

Załóżmy, że dodajemy klasę Ekran. Klasa ta wyświetla na bieżąco interfejs użytkownika.

```
class Screen {
public:
  void Display();
  
private:
  void Process();

  Monitor monitor_;
}
```

Chcemy teraz stworzyć klasę Ekran dotykowy, który również umożliwia odczyt akcji od użytkownika i ich wyświetlanie.

```
class TouchableScreen {
public:
  void Display();
  void GetUserInput();

private:
  void Process();
  void DispalyKeyboard();

  Monitor monitor_;
}
```

-Pytanie: Jak uprościć powyższy kod?

```
class Screen {
public:
  void Display();
  
private:
  void Process();

  Monitor monitor_;
}

class TouchableScreen : public Screen {
public:
  void GetUserInput();

private:
  void DispalyKeyboard();
}
```

### Wielodziedziczenie:

```
class Screen {
public:
  void Display();
  
private:
  void Process();

  Monitor monitor_;
}

class TouchableScreen : public Screen {
public:
  void GetUserInput();

private:
  void DispalyKeyboard();
}

Class Computer {
public:
  void TurnOn();
  void PowerOff();
  void Restart();
  
protected:
  Processor processor_;
  Drive drive_;
  Motherboard motherboard_;
  GraphicsCard graphics_card_;
  Memory memory_;
}

class Laptop : public Computer, public Screen{
public:
  
private:
  Keyboard keyboard_;
}

class Tablet : public Computer, public TouchableScreen {
public:
private:
}
```

Wybór implementacji zależy od programisty. Nie zawsze wielodziedziczenie będzie lepszym rozwiązaniem. Należy się zawsze zastanowić
czy dziedziczenie po konkretnej klasie uprości nam program i czy nie będzie powodować żadnych komplikacji w dalszym procesie
rozbudowy naszego programu.

```
class Bird {
public:
  Fly();
  MakeSound();
}

class Penguin {
public:
  Swim();
  MakeSound();
}

// Hummingbird is the type of bird which produces so little sound so it can be said that it makes no sound. 
// They do not have large proper voice box so they cannot create sounds like other birds. 
//They can communicate in a different manner or nonetheless.
class Hummingbird {
  Fly();
}
```
Jeżeli sprobujemy teraz uprościć klasę poprzez dziedziczenie pojawi się problem:
```
class Bird {
public:
  Fly();
  MakeSound();
}

class Penguin : public Bird{
public:
  Fly(); // But I can't fly!
  Swim();
  MakeSound();
}

class Hummingbird : public Bird{
  Fly();
  MakeSound(); // But I don't make sound!
}
```
Jeszcze bardziej utrudnimy sytuacje, gdy w przyszłości dodamy sobie kolejne klasy jak Struś.
Zawsze przed implementacją musimy się zastanowić jak podzielić odpowiedzialność na poszczególne klasy, aby
uniknąć podobnych problemów.

Jednym z pomysłów jest tworzenie interfejsów ich dziedziczenie oraz przeciążanie implementacji metod z klas bazowych.
```
class Bird {
public:
  size_t GetWeight();
  size_t GetHeight();
  size_t GetName();
  
  // Pure virtual function without implementation
  virtual void Eat() = 0;
  virtual void Sleep() = 0;
  
protectd:
  size_t weight_;
  size_t height_;
  std::sting name_;
}
```
```
class Flyable {
public:
  virtual void Fly() = 0;
  
private:
  Wings wings_;
}
```
```
class Swimmable {
public:
  virtual void Swim() = 0;
}
```
```
class Singingable {
public:
  virtual void MakeSound() = 0;
}
```
```
class Penguin : public Bird, public Swimmable {
public:
  // Override from Bird
  void Eat() override;
  void Sleep() override;
  
  // Override from Swimmable
  void Swim() override;
}

class Hummingbird : public Bird, public Flyable, public Singingable {
public:
  // Override from Bird
  void Eat() override;
  void Sleep() override;
  
  // Override from Singingable
  void MakeSound() override;
  
  // Override from Flyable
  void Fly() override;
}

class Goose : public Bird, public Flyable, public Singingable, public Swimmable {
public:
  // Override from Bird
  void Eat() override;
  void Sleep() override;
  
  // Override from Singingable
  void MakeSound() override;
  
  // Override from Flyable
  void Fly() override;
  
  // Override from Swimmable
  void Swim() override;
}
```
*WAŻNE* Klasa, która posiada co najmniej jedną czysto wirtualną metodę nie może być zainicjalizowana.
Możemy przechowywać wskaźnik wskazujący na typ tej klasy, ale nie możemy stworzyć jej instancji, ponieważ nie mamy zdefiniowanych 
jej zachowań. Klasa taka nazywa się abstrakcyjną, służy tylko
do ujednolicania interfejsu, a nie tworzenia obiektów. Dopiero klasa, która zaimplementuje wszystkie
brakujące metody, może zostać utworzona.

Słowo virtual i override.

Jeżeli chcemy, aby jakaś metoda była wirtualna, lub można ją było przeciążyć, należy poinformować kompilator słowem `virtual`.
Jeżeli w klasie pochodnej przeciążamy taką metodę, należy dodać słowo `override`.

```
class Interface {
public:
  virtual void DoSth() = 0;
};

class SomeClass : public Interface {
public:
  DoSth() override;
}

Interface interface; // Wrong, class Interface is pure virtual!
SmomeClass someClass; // Good!
Interface* interface = &someClass; // Good! We hold pointer!
```

# 3 Polimorfizm

Wracając do przykładu o ptakach, klasy `Penguin`, `Hummingbird` oraz `Goose` to klasy pochodne, które dziedziczą po pewnych klasach bazowych jak `Bird`, `Flyable`, `Singingable`, `Swimmable` oraz przeciążają kilka ich metod jak:
  - `void Eat() override;`,
  - `void Sleep() override;`,
  - `void MakeSound() override;`,
  - `void Fly() override;`,
  - `void Swim() override;`.
  
Przeciążanie takich metod powoduje, że możemy zmienić nieco implementacje konkretnych metod:

```
class Singingable {
public:
  virtual void MakeSound() = 0;
}
```
```
class Goose : public Singingable {
public:
  // Override from Singingable
  void MakeSound() override { std::cout << "Honk! Honk!"; }
}
```
```
class Hen : public Singingable {
public:
  // Override from Singingable
  void MakeSound() override { std::cout << "Cluck! Cluck!"; }
}
```
```
class Duck : public Singingable {
public:
  // Override from Singingable
  void MakeSound() override { std::cout << "Quack! Quack!"; }
}
```
Ponieważ wspólnym rodzicem wszystkich klas jest klasa `Singingable` możemy przechowywać w kontenerze wskaźniki typu `Singingable`.
`std::vector<std::shared_ptr<Singingable>> birds_;`

-Pytanie: Jakie dane otrzymamy na wyjściu?
```
std::vector<std::shared_ptr<Singingable>> birds_;
birds_.push_back(std::make_shared<Goose>());
birds_.push_back(std::make_shared<Hen>());
birds_.push_back(std::make_shared<Duck>());

std::cout << birds_[0]->MakeSound() << '\n';
std::cout << birds_[1]->MakeSound() << '\n';
std::cout << birds_[2]->MakeSound() << '\n';
```

Zjawisko, które właśnie obserwowaliśmy, nazywa się polimorfizmem.
Polimorfizm pozwala funkcji przybrać różne formy jak na przykładzie.
Dlatego, jeżeli utworzymy kolejno obiekty `Goose`, `Hen` i `Duck` w zależności
od obiektu zostanie wywołana jego wersja metody `MakeSound`.

-Pytanie: Kto grał lub czytał Wiedźmina?

W uniwersum wykreowanym przez naszego rodzimego pisarza: Andrzeja Sapkowskiego, występuje pewna
intrygująca i ciekawa rasa zwana Dopplerami. Rasa ta potrafi przyjąć, postać różnych form życia,
może stać się człowiekiem, elfem, krasnoludem. Zmienia w ten sposób swoje cechy jak głos, kolor włosów, a nawet ubranie!
Pomimo że rasa ta jest typu Doppler, potrafi w różnych okolicznościach podszywać się pod inne rasy jak elf, krasnolud czy człowiek.
Z punktu widzenia C++ nasz Doppler podlega zjawisku polimorfizmu.

``` 
class Doppler {
public:
  virtual SayHallo() { std::cout << "I'm Doppler!";
}

class Dwarf : public Doppler {
  virtual SayHallo() { std::cout << "I'm Dwarf!";
}

class Elf : public Doppler {
  virtual SayHallo() { std::cout << "I'm Elf!";
}

class Human : public Doppler {
  virtual SayHallo() { std::cout << "I'm Human!";
}

int main() {
  std::shared_ptr<Doppler> doppler1 = std::make_shared<Dwarf>();
  std::shared_ptr<Doppler> doppler2 = std::make_shared<Elf>();
  std::shared_ptr<Doppler> doppler3 = std::make_shared<Human>();
  
  std::cout << doppler1->SayHallo() << '\n';
  std::cout << doppler2->SayHallo() << '\n';
  std::cout << doppler3->SayHallo() << '\n';
}
```
Jak widzimy, nasz Doppler może przyjąć różne formy i zachowywać się tak jak one. Pomimo że wskaźnik jest typu Doppler.
Program dobrze wie, kiedy Doppler podszywa się pod człowieka, kiedy pod krasnoluda, a kiedy pod elfa.

Bardzo ważne w przypadku tworzenia metod wirtualnych i dziedziczenia jest tworzenie wirtualnych destruktorów.
Jeżeli korzystamy z dobroci polimorfizmu i nie oznaczymy destruktor jako `virtual` lub w klasach pochodnych jako `override`, to destruktor ten nie zostanie wywołany.

```
#include <iostream>
#include <string>

class Parent {
public:
  Parent() { std::cout << "PARENT C'tor called\n"; }
  ~Parent() { std::cout << "PARENT D'tor caller\n"; }
};

class Child : public Parent {
public:
  Child() { std::cout << "CHILD C'tor called\n"; }
  ~Child() { std::cout << "CHILD D'tor caller\n"; }
};

int main() {
  Child child;
}
```

```
#include <iostream>
#include <memory>
#include <string>

class Parent {
public:
  Parent() { std::cout << "PARENT C'tor called\n"; }
  ~Parent() { std::cout << "PARENT D'tor caller\n"; }
};

class Child : public Parent {
public:
  Child() { std::cout << "CHILD C'tor called\n"; }
  ~Child() { std::cout << "CHILD D'tor caller\n"; }
};

int main() {
  // Problem
  std::unique_ptr<Parent> child2 = std::make_unique<Child>();
  
  // But shared_ptr will clenup propelry
  std::shared_ptr<Parent> child2 = std::make_shared<Child>();
}
```
```
#include <iostream>
#include <memory>
#include <string>

class Parent {
public:
  Parent() { std::cout << "PARENT C'tor called\n"; }
  virtual ~Parent() { std::cout << "PARENT D'tor caller\n"; }
};

class Child : public Parent {
public:
  Child() { std::cout << "CHILD C'tor called\n"; }
  ~Child() override { std::cout << "CHILD D'tor caller\n"; }
};

int main() {
  std::unique_ptr<Parent> child2 = std::make_unique<Child>();
}
```

# 4 Zmienne i funkjce statyczne

Czasami chcielibyśmy przypisać jakąś stałą cechę do klasy. Nie konkretnych obiektów a klasy samej w sobie. Np. Każdy obiekt klasy
ma nazwę "Obiekt".
```
class Object {
public:
  std::string GetName() const { return name_; }
private:
  const std::string name_ = "Object";
}
```
W celu otrzymania nazwy tego obiektu, musimy najpierw utworzyć obiekt, a następnie zawołać `GetName()`.
```
int main() {
  Object obj;
  std::cout << obj.GetName() << '\n';
}
```
Nawet jeżeli obiekt zajmowałby dużo miejsca w pamięci a my chcielibyśmy tylko jego nazwę i tak musimy go utworzyć, ponieważ tylko na nim możemy zawołać metodę `GetName()`.

Rozwiązaniem tej uciążliwości jest static. Co więcej, problem ten możemy rozwiązać na 2 sposoby:

```
class Object {
class Object {
public:
  static std::string GetName() { return "Object"; }
};

class Object2 {
public:
  static std::string name_;
};

std::string Object2::name_{"Object2"};

int main() {
  std::cout << Object::GetName() << '\n';
  std::cout << Object2::name_ << '\n';

  return 0;
}
```
Nie musimy w ten sposób tworzyć specjalnie obiketu, aby dostać się do cechy klasy, jaka jest jej nazwa.

# Sekcja pytań i odpowiedzi
