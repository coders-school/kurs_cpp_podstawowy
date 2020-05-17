class Cargo {
public:
  Cargo() = default;
	Cargo(size_t amount, std::string name, size_t base_price);

  std::string GetName();
	size_t GetAmount();
	size_t GetBasePrice();
  Cargo& operator+=(size_t amount) {
    amount_ += amount;
    return *this;
  }
	Cargo& operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
  }

protected:
  std::string name_;
	size_t amount_;
  size_t base_price_;
};
