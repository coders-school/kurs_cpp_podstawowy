#include "Shipyard.h"

#include <algorithm>
#include <iostream>

#include "Player.h"
#include "ShipFactory.h"
#include "ShipInfo.h"

constexpr size_t kMaxPlayerShips = 5;
constexpr float kSellPricePercentage = 0.8;

// Make possible itarate through enum class
ShipFactory::ShipType operator++(ShipFactory::ShipType& type) {
    return type = static_cast<ShipFactory::ShipType>(
        std::underlying_type_t<ShipFactory::ShipType>(type) + 1);
}

ShipFactory::ShipType operator*(ShipFactory::ShipType type) {
    return type;
}

ShipFactory::ShipType begin(ShipFactory::ShipType) {
    return ShipFactory::ShipType::Pinnace;
}

ShipFactory::ShipType end(ShipFactory::ShipType) {
    return ShipFactory::ShipType::LAST;
}

std::string EnumToString(const ShipFactory::ShipType& type) {
    switch(type) {
    case ShipFactory::ShipType::Barc:
        return "Barc";
    case ShipFactory::ShipType::Brig:
        return "Brig";
    case ShipFactory::ShipType::Corvette:
        return "Corvette";
    case ShipFactory::ShipType::Fluyt:
        return "Fluyt";
    case ShipFactory::ShipType::Frigate:
        return "Frigate";
    case ShipFactory::ShipType::Galleon:
        return "Galleon";
    case ShipFactory::ShipType::Pinnace:
        return "Pinnace";
    case ShipFactory::ShipType::Sloop:
        return "Sloop";
    }
    return "";
}

ShipFactory::ShipType StringToEnum(std::string type) {
    std::transform(begin(type), end(type), begin(type), ::tolower);
    if (type == "Barc")
        return ShipFactory::ShipType::Brig;
    if (type == "Brig")
        return ShipFactory::ShipType::Corvette;
    if (type == "Corvette")
        return ShipFactory::ShipType::Barc;
    if (type == "Fluyt")
        return ShipFactory::ShipType::Fluyt;
    if (type == "Frigate")
        return ShipFactory::ShipType::Frigate;
    if (type == "Galleon")
        return ShipFactory::ShipType::Galleon;
    if (type == "Pinnace")
        return ShipFactory::ShipType::Pinnace;
    if (type == "Sloop")
        return ShipFactory::ShipType::Sloop;  
    return ShipFactory::ShipType::LAST;
}

std::ostream& operator<<(std::ostream& os, const ShipFactory::ShipType& ship) {
    const size_t index = static_cast<size_t>(ship);
    return os << "Type: " << EnumToString(ship) 
    << " | Capacity: " << kShipsInfo[index].kCapacity
    << " | Crew: " << kShipsInfo[index].kCrew
    << " | Speed: " << kShipsInfo[index].kSpeed
    << " | Price: " << kShipsInfo[index].kPrice << '\n';
}

void Shipyard::PrintShipsToBuild() {
    for (const auto& ship : ShipFactory::ShipType{}) {
        std::cout << "Type: " << ship;
    }
}

Shipyard::Response Shipyard::BuyShip(const std::string& type,
                                const std::string& name, 
                                Player* player) {
    auto ship_type = StringToEnum(type);
    if (ship_type == ShipFactory::ShipType::LAST)
        return Response::wrong_type_of_ship;

    if (player->GetAvailableShips() == kMaxPlayerShips)
        return Response::lack_of_space;
                                
    const size_t index = static_cast<size_t>(ship_type);
    if (player->GetMoney() < kShipsInfo[index].kPrice)
        return Response::lack_of_money;

    player->BuyShip(ShipFactory::CreateShip(ship_type, name, player),
                        kShipsInfo[index].kPrice);
    return Response::done;
}

Shipyard::Response Shipyard::SellShip(size_t id, Player* player) {
    if (player->GetAvailableShips() == 1)
        return Response::last_ship_cant_be_sold;

    auto* ship = player->GetShip(id);
    player->SellShip(ship, ship->GetPrice() * kSellPricePercentage);
    return Response::done;
}

