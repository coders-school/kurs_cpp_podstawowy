#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "Cargo.h"
#include "GTime.h"

// Class is resposible for Ship management. Every ship has
// capacity_ which is max amount of cargo to store in ship
// crew_ which is needed to operate ship. Every sailor need 1 money per day as payment
// speed_ descibes how many distance ship can travel per day
// name_ and id_ represent specific ship
// cargo_ is variable which store all goods on board
class Ship : public Time::Observer {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
        virtual void PayCrew(size_t money) = 0;
    };

    using Amount = size_t;

	Ship() = default;
    Ship(int capacity, int crew, int speed, size_t id, size_t price,
        std::string name, Delegate* delegate);
	~Ship() override;
    void PrintCargo() const;
    void Load(const Cargo* cargo, size_t amount);
    // Return how many cargo was unloaded
    size_t TryUnload(const Cargo* cargo, size_t amount);
	size_t GetSpeed() const { return speed_; }
    size_t GetPrice() const { return price_; }
    size_t GetId() const { return id_; }
    size_t GetCapacity() const { return capacity_; }
    size_t GetAvailableCapacity() const { return available_capacity_; }
	const Cargo* GetCargo(const std::string& name) const;

    // Override from Time::Observer
	void NextDay() override;

    friend std::ostream& operator<<(std::ostream& os, const Ship& ship);

private:
    void RemoveFromStorage(const Cargo* cargo);

    const size_t capacity_;
    const size_t crew_;
    const size_t speed_;
    const size_t id_;
    const size_t price_;
    const std::string name_;
    Delegate* delegate_;
    std::map<const Cargo*, Amount> cargo_;
    size_t available_capacity_;
};

#endif // SHIP_H
