#ifndef SHIPYARD_H
#define SHIPYARD_H

#include <iostream>
#include <memory>
#include <string>

#include "Ship.h"
#include "ShipFactory.h"

class Player;

class Shipyard {
public:
    enum class Response {done, 
                        lack_of_money, 
                        lack_of_space, 
                        last_ship_cant_be_sold,
                        wrong_type_of_ship};

    void PrintShipsToBuild();
    Response BuyShip(const std::string& type,
                    const std::string& name, 
                    Player* delegate);
    Response SellShip(size_t id, Player* player);

private:
    friend std::ostream& operator<<(std::ostream& os, const ShipFactory::ShipType& ship);
};

#endif // SHIPYARD_H