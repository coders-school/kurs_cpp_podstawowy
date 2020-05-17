#include "Store.h"

#include <algorithm>

#include "Cargo.h"
#include "CargoTypeServiceLocator.h"
#include "TimeServiceLocator.h"

constexpr size_t kMaxAmountOfCargo = 100;
constexpr size_t kMinAmountOfCargo = 10;
constexpr int kMaxChangeCargo = 5;
constexpr int kMinChangeCargo = -5;

std::ostream& operator<<(std::ostream& out, const Store& store) {
	out << "List of available cargo in store:\n";
	std::for_each(begin(store.cargo_), end(store.cargo_),
		[&out, &store, i{0}](const auto& cargo) mutable {
		out << ++i << "| " << *cargo.first 
			<< " Amount: " << cargo.second
			<< " SELL PRICE: " 
			<< store.RecalculateCargoSellPrice(cargo) 
			<< " BUY PRICE: " 
			<< store.RecalculateCargoBuyPrice(cargo) << "\n";
	});
	return out;
}

Store::Store(): cargo_types_(CargoTypeServiceLocator::GetCargoType()) {
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
	for (auto& cargo : cargo_) {
		int change = cargo_changer(gen_);
		if (change > cargo.second)
			cargo.second = 0;
		else if (cargo.second + change > kMaxAmountOfCargo)
			cargo.second = kMaxAmountOfCargo;
		else
			cargo.second += change;
	}
}

const Cargo* Store::GetCargo(const std::string& name) {
	auto found = std::find_if(begin(cargo_), end(cargo_),
		[&name](const auto& pair){
			return pair.first->GetName() == name;
	});

	return found != std::end(cargo_) ? found->first : nullptr;
}

Store::Response Store::Buy(const Cargo* cargo, size_t amount, Player* player) {
	if (cargo_[cargo] < amount)
		return Response::lack_of_cargo;
	if (player->GetAvailableSpace() < amount)
		return Response::lack_of_space;

	const size_t price = GetCargoBuyPrice(cargo, amount);
	if (price > player->GetMoney())
		return Response::lack_of_money;
	
	cargo_[cargo] -= amount;
	player->PurchaseCargo(cargo, price, amount);

	return Response::done;
}

Store::Response Store::Sell(const Cargo* cargo, size_t amount, Player* player) {
	if (cargo_[cargo] + amount > kMaxAmountOfCargo)
		return Response::lack_of_space;

	const size_t price = GetCargoSellPrice(cargo, amount);
	cargo_[cargo] += amount;
	player->SellCargo(cargo, price, amount);

	return Response::done;
}

void Store::GenerateCargo() {
	std::uniform_int_distribution<> amount_of_cargo_dist(
		kMinAmountOfCargo, kMaxAmountOfCargo);

	for (const auto* cargo : cargo_types_->GetAvailableCargo()) {
		cargo_[cargo] = amount_of_cargo_dist(gen_);
	}
}

size_t Store::RecalculateCargoBuyPrice(const CargoInfo& cargo_info) const {
	// Minimum price for cargo is 0.5 of base price when stock is full
	// Maximum price for cargo is 2.5 of base price when stock is empty
	// Minimum sell price is 1
	return std::max(1.0, cargo_info.first->GetBasePrice() * 
		(2.5 - (float(2 * cargo_info.second) / kMaxAmountOfCargo)));
}

size_t Store::RecalculateCargoSellPrice(const CargoInfo& cargo_info) const {
	// Minimum price for cargo is 0.25 of base price when stock is full
	// Maximum price for cargo is 2.25 of base price when stock is empty
	return cargo_info.first->GetBasePrice() * 
		(2.25 - (float(2 * cargo_info.second) / kMaxAmountOfCargo));
}

size_t Store::GetCargoSellPrice(const Cargo* cargo, size_t amount) const {
	// We need to recalculate cargo price every 1 item sold
	// to simulate price change during transaction
	auto current = cargo_.at(cargo);
	size_t price {0};
	for (size_t i = 0 ; i < amount ; ++i) {
		price += RecalculateCargoSellPrice(std::make_pair(cargo, current));
		++current;
	}

    return price;
}

size_t Store::GetCargoBuyPrice(const Cargo* cargo, size_t amount) const {
	// We need to recalculate cargo price every 1 item bought
	// to simulate price change during transaction
	auto current = cargo_.at(cargo);
	size_t price {0};
	for (size_t i = 0 ; i < amount ; ++i) {
		price += RecalculateCargoBuyPrice(std::make_pair(cargo, current));
		--current;
	}

    return price;
}

void Store::SetAmountForTesting(const Cargo* cargo, size_t amount) {
	cargo_[cargo] = amount;
}