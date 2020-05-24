<!-- .slide: data-background="#111111" -->

# Podstawy C++

## enum i enum class

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

enum to inaczej typ wyliczeniowy, w C++11 zaprezentowano także enum class zwany silnym type wyliczeniowym.

Załóżmy, że piszemy oprogramowanie do pralki.
Chcielibyśmy utworzyć także interfejs zwracający numer błędu np. 
  - brak wody,
  - zbyt duże obciążenie,
  - problem z łożyskami,
  - blokada pompy ect.
  
odpowiedzą na to jest typ eum:
```
enum ErrorCode {
  lack_of_water;
  to_much_load;
  bearing_problem;
  block_of_pump;
}
```
lub enmum class:
```
enum class ErrorCode {
  lack_of_water;
  to_much_load;
  bearing_problem;
  block_of_pump;
}
```

Typ enum numerowany jest od 0 do n, gdzie n liczba elementów. Jeżeli chcemy nadać inne wartości musimy to zrobić ręcznie:

```
enum class ErrorCode {
  lack_of_water = 333;
  to_much_load; // will be 334
  bearing_problem = 600;
  block_of_pump; // will be 601
}
```

enum od enum class różni się głownie tym, że możemy niejawnie skonwertować typ enum na int (w końcu to typ wyliczeniowy).
Natomiast typ enum class możemy skonwertować na int, poprzez rzutowanie. Nie będziemy na razie omawiać rzutowania. Warto tylko
pamiętać że robimy to wywołując `int num = static_cast<int>(ErrorCode::lack_of_water)`. 

Pytanie - W jakich innych przepadkach zastosowalibyście typ wyliczeniowy?

Druga różnica polega na tym, że dla enum możemy mieć konflikt nazw, natomiast dla enum class nie.
```
   enum color{
      RED,
      GREEN,
      BLUE,
      YELLOW
   }
   enum traffic_light {
      RED,
      YELLOW,
      GREEN
   }
   
   auto light_color = GetColor();
   if (light_color == RED) {
      Stop();
   } else {
      Go();
   }
```
 
Aby uniknąć konfliktu nazw stosujemy enum class:
```
   enum class color{
      RED,
      GREEN,
      BLUE,
      YELLOW
   }
   enum class traffic_light {
      RED,
      YELLOW,
      GREEN
   }
   
   auto light_color = GetColor();
   if (light_color == traffic_light::RED) {
      Stop();
   } else {
      Go();
   }
```
