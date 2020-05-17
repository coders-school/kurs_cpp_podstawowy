class Cargo {
public:
  Cargo() = default;
  Cargo(size_t amount, std::string name, size_t base_price);
  virtual ~Cargo() = default;

  virtual size_t GetPrice() const = 0;
  virtual std::string GetName() const = 0;
  virtual size_t GetAmount() const = 0;
  virtual size_t GetBasePrice() const = 0;
  virtual Cargo& operator+=(size_t amount) = 0;
  virtual Cargo& operator-=(size_t amount) = 0;

protected:
  std::string name_;
  size_t amount_;
  size_t base_price_;
};

class Fruit : public Cargo {
public:
  Fruit(size_t amount, const std::string& name, size_t base_price,
	size_t expiry_date, size_t time_elapsed);
  ~Fruit() override;

  // override from Cargo
  size_t GetPrice() const override {
    if (time_elapsed_ >= expiry_date_)
      return 0;
    return static_cast<size_t>(
      base_price_ * ((float)(expiry_date_ - time_elapsed_)) / expiry_date_);
  }
  std::string GetName() const override { return name_; }
  size_t GetAmount() const override { return amount_; }
  size_t GetBasePrice() const override { return base_price_; }
  Cargo& operator--() { --amount_; return *this; }
  Cargo& operator+=(size_t amount) {
     amount_ += amount;
     return *this;
  }
  Cargo& operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
  }

  size_t GetTimeElapsed() const { return time_elapsed_; }
  size_t GetExpiryDate() const { return expiry_date_; }

private:
  size_t time_elapsed_{ 0 };
  size_t expiry_date_;
};

class Alcohol : public Cargo {
public:
  Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage);
  ~Alcohol() override = default;
    
  // override from Cargo
  size_t GetPrice() const override { return base_price_ * percentage_ / 96; }
  std::string GetName() const override { return name_; }
  size_t GetAmount() const override { return amount_; }
  size_t GetBasePrice() const override { return base_price_; }
  Cargo& operator+=(size_t amount) {
    amount_ += amount;
    return *this;
  }
  Cargo& operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
  }

  size_t GetPercentage() const { return percentage_; }

private:
  size_t percentage_;
};

class Item : public Cargo {
public:
  enum class Rarity { common = 1, rare = 3, epic = 6, legendary = 10 };

  Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity);
  ~Item() override = default;
    
  // override from Cargo
  size_t GetPrice() const override { return base_price_ * static_cast<int>(rarity_); }
  std::string GetName() const override { return name_; }
  size_t GetAmount() const override { return amount_; }
  size_t GetBasePrice() const override { return base_price_; }
  Cargo& operator+=(size_t amount) {
    amount_ += amount;
    return *this;
  }
  Cargo& operator-=(size_t amount) {
    amount_ -= amount;
    return *this;
  }

  Rarity GetRarity() const { return rarity_; }

private:
    Rarity rarity_;
};
