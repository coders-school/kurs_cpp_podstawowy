class DryFruit : public Fruit {
public:
  // override from Cargo
  std::string GetName() const override { return "Dry Fruit"; }
  size_t GetPrice() const override {
    if (time_elapsed_ >= expiry_date_)
      return 0;
    return static_cast<size_t>(
      3 * base_price_ * ((float)(expiry_date_ - time_elapsed_)) / expiry_date_);
  }

  // override from Fruit
  Cargo& operator--() override { 
    if (++counter_ == 10) {
        ++time_elapsed_;
        counter_ = 0;
    }
    return *this;
  };
  
private:
  size_t counter_{0};
};
