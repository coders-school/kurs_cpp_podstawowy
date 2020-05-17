#include "Store.h"

#include <algorithm>
#include <random>

#include "Alcohol.h"
#include "Fruit.h"
#include "Item.h"

constexpr size_t kAmountOfDiffrentCargo = 10;
constexpr size_t kMaxAmountOfCargo = 100;
constexpr size_t kMinAmountOfCargo = 10;
constexpr size_t kMinBasePrice = 5;
constexpr size_t kMaxBasePrice = 15;
constexpr size_t kTypeOfCargo = 2;
constexpr size_t kMinPercentage = 10;
constexpr size_t kMaxPercentage = 96;
constexpr size_t kMinTimeToSpoil = 10;
constexpr size_t kMaxTimeToSpoil = 20;
constexpr size_t kRarityMax = 10;
constexpr char kAlcoholName[] = "Acohol";
constexpr char kFruitlName[] = "Fruit";
constexpr char kItemlName[] = "Item";

std::unique_ptr<Cargo> CreateCargo(Cargo* cargo, size_t amount, Time* time) {
	if (auto* alcohol = dynamic_cast<Alcohol*>(cargo))
		return std::make_unique<Alcohol>(amount, alcohol);
	else if (auto* fruit = dynamic_cast<Fruit*>(cargo))
		return std::make_unique<Fruit>(amount, fruit, time);
	else if (auto* item = dynamic_cast<Item*>(cargo))
		return std::make_unique<Item>(amount, item);

	return nullptr;
}

Item::Rarity GetRarity(size_t num) {
	if (num < 4) {
		return Item::Rarity::common;
	} else if (num < 7) {
		return Item::Rarity::rare;
	} else if (num < 10) {
		return Item::Rarity::epic;
	}
	return Item::Rarity::legendary;
}

enum class TypeOfCargo { Alcohol = 0, Fruit = 1, Item = 2 };
std::unique_ptr<Cargo> CreateCargo(TypeOfCargo type, 
								size_t amount, 
								size_t base_price,
								std::mt19937& gen,
								Time* time) {
	switch(type) {
	case TypeOfCargo::Alcohol: {
		std::uniform_int_distribution<> percentage_dist(
			kMinAmountOfCargo, kMaxAmountOfCargo);	
		return std::make_unique<Alcohol>(amount, kAlcoholName,
			base_price, percentage_dist(gen));
		break;
		}
	case TypeOfCargo::Fruit: {
		std::uniform_int_distribution<> expiry_date_dist(
			kMinTimeToSpoil, kMaxTimeToSpoil);
		return std::make_unique<Fruit>(amount, kFruitlName,
			base_price, expiry_date_dist(gen), time);
		break;
		}
	case TypeOfCargo::Item: {
		std::uniform_int_distribution<> rarity_dist(
			0, kRarityMax);
		return std::make_unique<Item>(amount, kItemlName,
			base_price, GetRarity(rarity_dist(gen)));
		break;
		}
	}
	return nullptr;
}

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

Store::Store(Time* time):
	time_(time) {
	time_->AddObserver(this);
	GenerateCargo();
}

Store::~Store() {
	time_->RemoveObserver(this);
}

void Store::NextDay() {
	static size_t counter = 0;
	if (counter++ > 5) {
		counter = 0;
		cargo_.clear();
		GenerateCargo();
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
	auto purhased_cargo = CreateCargo(cargo, amount, time_);
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
		cargo_.push_back(CreateCargo(cargo, amount, time_));
	}
	*cargo -= amount;
	player->SellCargo(cargo, price);

	return Response::done;
}

void Store::GenerateCargo() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> amount_of_cargo_dist(
		kMinAmountOfCargo, kMaxAmountOfCargo);
	std::uniform_int_distribution<> base_price_dist(
		kMinBasePrice, kMaxBasePrice);
	std::uniform_int_distribution<> type_of_cargo_dist(
		0, kTypeOfCargo);

	cargo_.reserve(kAmountOfDiffrentCargo);
	for (size_t i = 0 ; i < kAmountOfDiffrentCargo ; ++i) {
		cargo_.push_back(CreateCargo(
			static_cast<TypeOfCargo>(type_of_cargo_dist(gen)), 
			amount_of_cargo_dist(gen),
			base_price_dist(gen), gen,
			time_
		));
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