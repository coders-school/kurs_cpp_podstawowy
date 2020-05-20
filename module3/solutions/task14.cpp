#include <iostream>
#include <memory>

std::shared_ptr<int> foo(int lhs, int rhs) {
  std::shared_ptr<int> result = std::make_shared<int>(lhs * rhs);
  std::cout << "num: " << *result << " | owners: " << result.use_count() << "\n";

  return result;
}

int main() {
  auto number = foo(10, 20);
  std::cout << "num: " << *number << " | owners: " << number.use_count() << "\n";

  return 0;
}
