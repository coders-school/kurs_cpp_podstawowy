#include <iostream>
#include <memory>

std::shared_ptr<int> foo(int first, int second)
{
    return std::make_shared<int>(first * second);
}

int main() {
    auto number = foo(10, 20);
    std::cout << "num: " << *number << " | owners: " << number.use_count() << "\n";

    return 0;
}
