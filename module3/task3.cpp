#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> number){
    *number = 20;
    std::cout << "foo() function     Number = " << *number << " | Pointers quantity = " << number.use_count() << "\n";
}
int main() {
    std::shared_ptr<int> number = std::make_shared<int>(10);
    std::cout << "MAIN:    Number = " << *number << " | Pointers quantity = " << number.use_count() << "\n";
    foo(number);
    std::cout << "MAIN:    Number = " << *number << " | Pointers quantity = " << number.use_count() << "\n";

    return 0;
}
