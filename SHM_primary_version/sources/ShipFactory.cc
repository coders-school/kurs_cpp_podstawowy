#include "ShipFactory.h"

#include <string>

#include "ShipInfo.h"

// static
std::unique_ptr<Ship> ShipFactory::CreateShip(ShipType type, 
                        std::string name, 
                        Player::Delegate* delegate) {
    const size_t index = static_cast<size_t>(type); 
    return std::make_unique<Ship>(kShipsInfo[index].kCapacity,
            kShipsInfo[index].kCrew, kShipsInfo[index].kSpeed,
            ++id_, kShipsInfo[index].kPrice, name, delegate);
}

size_t ShipFactory::id_{0};