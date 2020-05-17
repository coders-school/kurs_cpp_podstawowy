#include "Alcohol.h"

#include <iostream>

Alcohol::Alcohol(size_t amount, const std::string& name, 
	size_t base_price, size_t percentage):
		Cargo(amount, name, base_price),
		percentage_(percentage) {

}

Alcohol::Alcohol(size_t amnount, const Alcohol* alcohol):
	Alcohol(amnount, alcohol->GetName(), alcohol->GetBasePrice(),
			alcohol->GetPercentage()){
}

std::ostream& Alcohol::Print(std::ostream& os) const {
	return os << "Name: " << name_ << " | amount: " << amount_ 
	<< " | percentage: " << percentage_; 
}

size_t Alcohol::GetPrice() const {
	return base_price_ * percentage_ / 96;
}

Cargo& Alcohol::operator+=(size_t amount) {
	amount_ += amount;
	return *this;
}

Cargo& Alcohol::operator-=(size_t amount) {
	amount_ -= amount;
	return *this;
}

bool Alcohol::operator==(const Cargo& cargo) const {
	if (typeid(*this) != typeid(cargo))
            return false;

	auto alcohol = dynamic_cast<const Alcohol&>(cargo);
	return alcohol.GetBasePrice() == base_price_
		&& alcohol.GetName() == name_
		&& alcohol.GetPercentage() == percentage_;
}