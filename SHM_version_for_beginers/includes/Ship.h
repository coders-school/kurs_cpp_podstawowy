#ifndef SHIP_H
#define SHIP_H

#include <memory>
#include <string>
#include <vector>

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

	Ship() = default;
    Ship(int capacity, int crew, int speed, std::string name,
        size_t id, Time* time, Delegate* delegate);
	~Ship() override;
    void PrintCargo() const;
    void Load(std::unique_ptr<Cargo> cargo);
    void Unload(Cargo* cargo);
	size_t GetSpeed() const { return speed_; }
	Cargo* GetCargo(size_t index) const;

    // Override from Time::Observer
	void NextDay() override;

private:
	Cargo* FindMatchCargo(Cargo* cargo);
	void RemoveFromStorage(Cargo* cargo);

    const size_t capacity_;
    const size_t crew_;
    const size_t speed_;
    const std::string name_;
    const size_t id_;
    Time* time_;
    Delegate* delegate_;
    std::vector<std::unique_ptr<Cargo>> cargo_;
};

#endif // SHIP_H