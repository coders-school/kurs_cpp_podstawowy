#include <iostream>
#include <memory>

// TODO: Implement foo()
// It should take 2 int values and return their product as a shared_ptr.
// Additionally, check how many owners are there.

std::shared_ptr<int> foo(int arg1, int arg2) {
    std::shared_ptr<int> product = std::make_shared<int>(arg1 * arg2);
    std::cout << "num: " << *product << " | owners: " << product.use_count() << "\n";
    return product;
}

int main() {
    auto number = foo(10, 20);
    std::cout << "num: " << *number << " | owners: " << number.use_count() << "\n";

    return 0;
}
