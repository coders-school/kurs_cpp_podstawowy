#include "Fruit.h"

#include <iostream>

#include "GTime.h"

Fruit::Fruit(size_t amount, const std::string& name, size_t base_price,
			 size_t expiry_date, Time* time) :
	Cargo(amount, name, base_price),
	expiry_date_(expiry_date),
	time_(time) {

	time_->AddObserver(this);
}

Fruit::~Fruit() {
	time_->RemoveObserver(this);
}

Fruit::Fruit(size_t amount, const std::string& name, size_t base_price, 
		size_t expiry_date, size_t time_elapsed, Time* time):
	Fruit(amount, name, base_price, expiry_date, time) {
	time_elapsed_ = time_elapsed;
}

Fruit::Fruit(size_t amnount, const Fruit* fruit, Time* time) :
	Fruit(amnount, fruit->GetName(), fruit->GetBasePrice(),
		fruit->GetExpiryDate(), fruit->GetTimeElapsed(), time) {
}

std::ostream& Fruit::Print(std::ostream& os) const {
	return os << "Name: " << name_ << " | amount: " << amount_ 
    << " | expirt date: " << expiry_date_ 
	<< " | time to spoil: " << expiry_date_ - time_elapsed_; 
}

size_t Fruit::GetPrice() const {
	if (time_elapsed_ >= expiry_date_)
		return 0;
	return static_cast<size_t>(
		base_price_ * ((float)(expiry_date_ - time_elapsed_)) / expiry_date_);
}

Cargo& Fruit::operator+=(size_t amount) {
	amount_ += amount;
	return *this;
}

Cargo& Fruit::operator-=(size_t amount) {
	amount_ -= amount;
	return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
	if (typeid(*this) != typeid(cargo))
            return false;

	auto fruit = static_cast<const Fruit&>(cargo);
	return fruit.GetBasePrice() == base_price_
		&& fruit.GetName() == name_
		&& fruit.GetExpiryDate() == expiry_date_
		&& fruit.GetTimeElapsed() == time_elapsed_;
}

void Fruit::NextDay() {
	if (time_elapsed_ == expiry_date_)
		return;
	++time_elapsed_;
}