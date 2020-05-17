#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "Cargo.h"

class Item : public Cargo {
public:
    enum class Rarity { common = 1, rare = 3, epic = 6, legendary = 10 };

    Item(size_t amount, const std::string& name, size_t base_price, Rarity rarity);
	Item(size_t amnount, const Item* item);
	~Item() override = default;
    
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
	void NextDay() override { /* Item class doesn't register observer */ }

	Rarity GetRarity() const { return rarity_; }

private:
    Rarity rarity_;
};

#endif // ITEM_H