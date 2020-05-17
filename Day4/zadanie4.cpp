#include <cmath>
#include <iostream>
  
class Coordinates {
public:
  Coordinates() = default;
  Coordinates(size_t pos_x, size_t pos_y) :
    pos_x_(pos_x), pos_y_(pos_y) {}
  static size_t Distance(const Coordinates& lhs, const Coordinates& rhs) {
    return std::sqrt(std::pow((int)lhs.pos_x_ - (int)rhs.pos_x_, 2)
      + std::pow((int)lhs.pos_y_ - (int)rhs.pos_y_, 2));
  }
  bool operator==(const Coordinates& lhs) const { 
    return this->pos_x_ == lhs.pos_x_ && this->pos_y_ == lhs.pos_y_; 
  }

private:
  const size_t pos_x_{ 0 };
  const size_t pos_y_{ 0 };
};
