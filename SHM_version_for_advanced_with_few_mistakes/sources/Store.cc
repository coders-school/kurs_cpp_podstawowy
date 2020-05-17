#include "Store.h"

#include <algorithm>

#include "Alcohol.h"
#include "CargoFactory.h"
#include "Fruit.h"
#include "Item.h"
#include "TimeServiceLocator.h"

constexpr size_t kMaxAmountOfCargo = 100;
constexpr size_t kMinAmountOfCargo = 10;
constexpr size_t kMaxBasePrice = 100;
constexpr size_t kMinBasePrice = 10;
constexpr int kMaxChangeCargo = 10;
constexpr int kMinChangeCargo = -10;

std::ostream& operator<<(std::ostream& out, const Store& store) {
	out << "List of available cargo in store:\n";
	std::for_each(begin(store.cargo_), end(store.cargo_),
		[&out, &store, i{0}](const auto& cargo) mutable {
		out << ++i << "| ";
		cargo->Print(out) << " SELL PRICE: " 
			<< store.RecalculateCargoSellPrice(cargo.get()) 
			<< " BUY PRICE: " 
			<< store.RecalculateCargoBuyPrice(cargo.get()) << "\n";
	});
	return out;
}

Store::Store() {
	TimeServiceLocator::GetTime()->AddObserver(this);
	std::random_device rd;
	gen_ = std::mt19937(rd());
	GenerateCargo();
}

Store::~Store() {
	TimeServiceLocator::GetTime()->RemoveObserver(this);
}

void Store::NextDay() {
	// We simulate buying and selling cargo in stock during time change
	std::uniform_int_distribution<> cargo_changer(kMinChangeCargo, kMaxChangeCargo);
	for (const auto& cargo : cargo_) {
		*cargo += cargo_changer(gen_);
	}
}

Cargo* Store::GetCargo(const size_t index) {
	if (cargo_.size() > index)
		return cargo_[index].get();
	return nullptr;
}

Store::Response Store::Buy(Cargo* cargo, size_t amount, Player* player) {
	if (cargo->GetAmount() < amount)
		return Response::lack_of_cargo;
	if (player->GetAvailableSpace() < amount)
		return Response::lack_of_space;

	const size_t price = GetCargoSellPrice(cargo, amount);
	if (price > player->GetMoney())
		return Response::lack_of_money;
	
	*cargo -= amount;
	auto purhased_cargo = CargoFactory::CreateCargo(cargo, amount);
	// If cargo was sold remove it from vector
	if (cargo->GetAmount() == 0)
		RemoveFromStore(cargo);

	player->PurchaseCargo(std::move(purhased_cargo), price);
	return Response::done;
}

Store::Response Store::Sell(Cargo* cargo, size_t amount, Player* player) {
	if (cargo->GetAmount() < amount)
		return Response::lack_of_cargo;

	size_t price = 0;
	// If identical cargo exist in store cumulate it, if not create new cargo
	if (auto* match_cargo = FindMatchCargo(cargo)) {
		if (match_cargo->GetAmount() + amount > kMaxAmountOfCargo)
			return Response::lack_of_space;
		price = GetCargoBuyPrice(match_cargo, amount);
		*match_cargo += amount;
	} else {
		// If we want to simplify, we can first create cargo, then add to store
		// and calculate price, like store has 0 amount of product.
		// but price will always be really high for player.
		// I decide to calculate overall needed for cargo
		// for example stroe hase enough cargo when one type of product is 250 or higher
		price = GetCargoBuyPrice(cargo, amount);
		cargo_.push_back(CargoFactory::CreateCargo(cargo, amount));
	}
	*cargo -= amount;
	player->SellCargo(cargo, price);

	return Response::done;
}

void Store::GenerateCargo() {
	std::uniform_int_distribution<> amount_of_cargo_dist(
		kMinAmountOfCargo, kMaxAmountOfCargo);
	std::uniform_int_distribution<> base_price_dist(
		kMinBasePrice, kMaxBasePrice);

	// CargoFactory::CargoType() -> () make an instance
	for (auto type : CargoFactory::CargoType()) {
		cargo_.push_back(CargoFactory::CreateCargo(
			type, amount_of_cargo_dist(gen_), base_price_dist(gen_)));
	}
}

Cargo* Store::FindMatchCargo(Cargo* cargo) const {
	auto match_cargo = std::find_if(std::begin(cargo_), std::end(cargo_),
		[cargo](const auto& el) {
		return *el == *cargo;
	});
	return match_cargo != std::end(cargo_) ? match_cargo->get() : nullptr;
}

void Store::RemoveFromStore(Cargo* cargo) {
	cargo_.erase(std::find_if(std::begin(cargo_), std::end(cargo_),
		[cargo](const auto& el) {
		return *el == *cargo;
	}));
}

size_t Store::RecalculateCargoBuyPrice(Cargo* cargo, size_t cargo_num) const {
	// If cargo is in store, use regular price
	if (auto stock_cargo = FindMatchCargo(cargo)) {
		// Minimum price for cargo is 0.25 of base price when stock is full
		// Maximum price for cargo is 2.25 of base price when stock is empty
		return cargo->GetPrice() * 
			(2.25 - (float(2 * cargo->GetAmount()) / kMaxAmountOfCargo));
	}

	// If cargo is not in store calculate price based on requisition of product
	const size_t requisition_of_product = 250;

	for (const auto& store_cargo : cargo_) {
		if (store_cargo->GetName() == cargo->GetName())
			cargo_num += store_cargo->GetAmount();
	}
	
	// If shop has 250 or more amount of product, 
	// price will be the lowest (0.25) * base_price
	// If shop has 0 amount of product,
	// price will be the highest (2.25) * base_price
	return cargo->GetPrice() * 
		(2.25 - (float(2 * cargo_num) / requisition_of_product));
}

size_t Store::RecalculateCargoSellPrice(Cargo* cargo) const {
	// Minimum price for cargo is 0.5 of base price when stock is full
	// Maximum price for cargo is 2.5 of base price when stock is empty
	// Minimum sell price is 1
	return std::max(1.0, cargo->GetPrice() * 
		(2.5 - (float(2 * cargo->GetAmount()) / kMaxAmountOfCargo)));
}

size_t Store::GetCargoSellPrice(Cargo* cargo, size_t amount) const {
	// We need to recalculate cargo price every 5 item bought
	// to simulate price change during transaction
	size_t price {0};
	size_t loop = amount / 5;
	for (size_t i = 0 ; i < loop ; ++i) {
		price += RecalculateCargoSellPrice(cargo) * 5;
		*cargo -= 5;
	}
	price += RecalculateCargoSellPrice(cargo) * amount % 5;
    // After calculation price, need restore previosu cargo amount
	*cargo += amount - amount % 5;

    return price;
}

size_t Store::GetCargoBuyPrice(Cargo* cargo, size_t amount) const {
	// We need to recalculate cargo price every 5 item sold
	// to simulate price change during transaction
	size_t price {0};
	size_t loop = amount / 5;
	for (size_t i = 0 ; i < loop ; ++i) {
		price += RecalculateCargoBuyPrice(cargo, i * 5) * 5;
		*cargo += 5;
	}
	price += RecalculateCargoBuyPrice(cargo) * amount % 5;
    // After calculation price, need restore previosu cargo amount
	*cargo -= amount - amount % 5;

    return price;
}

void Store::ClenupStore() {
	// When Cargo will be damged e.g. Fruit will spoil his price will be 0
	// We want to delete this elements.
	cargo_.erase(begin(cargo_), std::remove_if(begin(cargo_), end(cargo_),
		[](const auto& el){
			return el->GetPrice() == 0;
		})
	);
}