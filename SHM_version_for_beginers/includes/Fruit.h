#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
#include <string>

#include "Cargo.h"

class Time;

class Fruit : public Cargo {
public:
    Fruit(size_t amount, const std::string& name, 
		size_t base_price, size_t expiry_date, Time* time);
	Fruit(size_t amount, const std::string& name, size_t base_price,
		size_t expiry_date, size_t time_elapsed, Time* time);
	Fruit(size_t amnount, const Fruit* fruit, Time* time);
	~Fruit() override;

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
    void NextDay() override;

	size_t GetTimeElapsed() const { return time_elapsed_; }
	size_t GetExpiryDate() const { return expiry_date_; }

private:
	size_t time_elapsed_{ 0 };
    size_t expiry_date_;
	Time* time_;
};

#endif // FRUIT_H