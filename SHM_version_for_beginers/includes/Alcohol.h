#ifndef ALCOHOL_H
#define ALCOHOL_H
	
#include <iostream>
#include <string>

#include "Cargo.h"

class Alcohol : public Cargo {
public:
    Alcohol(size_t amount, const std::string& name, size_t base_price, size_t percentage);
	Alcohol(size_t amnount, const Alcohol* alcohol);
	~Alcohol() override = default;
    
    // override from Cargo
	std::ostream& Print(std::ostream& os) const override;
	size_t GetPrice() const override;
	std::string GetName() const override { return name_; }
	size_t GetAmount() const override { return amount_; }
	size_t GetBasePrice() const override { return base_price_; }
	Cargo& operator+=(size_t amount) override;
	Cargo& operator-=(size_t amount) override;
	bool operator==(const Cargo& cargo) const override;

    // override from Time::Observer
	void NextDay() override { /* Alcohol class doesn't register observer */ }

	size_t GetPercentage() const { return percentage_; }

private:
    size_t percentage_;
};

#endif // ALCOHOL_H