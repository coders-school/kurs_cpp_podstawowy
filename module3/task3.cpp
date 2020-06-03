#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> ptr)
{
    *ptr = 20;
    std::cout << "Value: " << *ptr << " use_count: " << ptr.use_count() << std::endl;
}

int main() {
    std::shared_ptr<int> number = std::make_shared<int>(10);
    std::cout << "Value: " << *number << " use_count: " << number.use_count() << std::endl;
    foo(number);
    std::cout << "Value: " << *number << " use_count: " << number.use_count() << std::endl;

    return 0;
}
