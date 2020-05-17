#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <map>
#include <memory>
#include <random>

#include "CargoTypes.h"
#include "Time.h"
#include "Player.h"

class Cargo;

// Class resposible for management of Cargo. Every Day Cargo can change
// it's price and amount on store.
class Store : public Time::Observer {
public:
    enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};
    using Amount = size_t;
    using CargoInfo = std::pair<const Cargo*, Amount>;

	Store();
	~Store() override;

    // override from Time::Observer
    void NextDay() override;

	const Cargo* GetCargo(const std::string& name);
    Response Buy(const Cargo* cargo, size_t amount, Player* player);
    Response Sell(const Cargo* caergo, size_t amount, Player* player);
    size_t RecalculateCargoSellPrice(const CargoInfo& cargo_info) const;
    size_t RecalculateCargoBuyPrice(const CargoInfo& cargo_info) const;
    size_t GetCargoSellPrice(const Cargo* cargo, size_t amount) const;
    size_t GetCargoBuyPrice(const Cargo* cargo, size_t amount) const;

	friend std::ostream& operator<<(std::ostream& out, const Store& store);

    // For testing
    void SetAmountForTesting(const Cargo* cargo, size_t amount);

private:
    void GenerateCargo();
	void RemoveFromStore(Cargo* cargo);

    CargoTypes* cargo_types_;
    std::map<const Cargo*, Amount> cargo_;
    std::mt19937 gen_;
};

#endif // STORE_H