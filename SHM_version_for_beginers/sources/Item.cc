#include "Item.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Item::Rarity& rarity) {
	switch (rarity)
	{
	case Item::Rarity::common:
		os << "common";
		break;
	case Item::Rarity::epic:
		os << "epic";
		break;
	case Item::Rarity::legendary:
		os << "legendary";
		break;
	case Item::Rarity::rare:
		os << "rare";
		break;
	default:
		os << "ERROR";
		break;
	}
	return os;
}

Item::Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity) :
	Cargo(amount, name, base_price),
	rarity_(rarity) {

}

Item::Item(size_t amnount, const Item* item) :
	Item(amnount, item->GetName(), item->GetBasePrice(),
		item->GetRarity()) {
}

std::ostream& Item::Print(std::ostream& os) const {
	return os << "Name: " << name_ << " | amount: " << amount_ 
	<< " | rarity: " << rarity_;
}

size_t Item::GetPrice() const {
	return base_price_ * static_cast<int>(rarity_);
}

Cargo& Item::operator+=(size_t amount) {
	amount_ += amount;
	return *this;
}

Cargo& Item::operator-=(size_t amount) {
	amount_ -= amount;
	return *this;
}

bool Item::operator==(const Cargo& cargo) const {
	if (typeid(*this) != typeid(cargo))
		return false;
		
	auto item = dynamic_cast<const Item&>(cargo);
	return item.GetBasePrice() == base_price_
		&& item.GetName() == name_
		&& item.GetRarity() == rarity_;
}