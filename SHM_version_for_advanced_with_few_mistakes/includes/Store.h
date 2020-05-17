#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <memory>
#include <random>
#include <vector>

#include "Cargo.h"
#include "Time.h"
#include "Player.h"

// Class resposible for management of Cargo. Every Day Cargo can change
// it's price and amount on store.
class Store : public Time::Observer {
public:
    enum class Response {done, lack_of_money, lack_of_cargo, lack_of_space};

	Store();
	~Store() override;

    // override from Time::Observer
    void NextDay() override;

	Cargo* GetCargo(const size_t pos);
    Response Buy(Cargo* cargo, size_t amount, Player* player);
    Response Sell(Cargo* caergo, size_t amount, Player* player);
    size_t RecalculateCargoSellPrice(Cargo* cargo) const;
    size_t RecalculateCargoBuyPrice(Cargo* cargo, size_t amount = 0) const;
    size_t GetCargoSellPrice(Cargo* cargo, size_t amount) const;
    size_t GetCargoBuyPrice(Cargo* cargo, size_t amount) const;

    // for testing
    void SetCargo(std::vector<std::unique_ptr<Cargo>>&& cargo) { cargo_ = std::move(cargo); }

	friend std::ostream& operator<<(std::ostream& out, const Store& store);

private:
    void GenerateCargo();
	Cargo* FindMatchCargo(Cargo* cargo) const;
	void RemoveFromStore(Cargo* cargo);
    void ClenupStore();

    std::vector<std::unique_ptr<Cargo>> cargo_;
    std::mt19937 gen_;
};

#endif // STORE_H