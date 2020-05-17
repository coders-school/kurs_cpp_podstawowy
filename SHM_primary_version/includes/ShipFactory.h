#ifndef SHIP_FACTORY_H
#define SHIP_FACTORY_H

#include <memory>

#include <Player.h>
#include <Ship.h>

class ShipFactory {
public: 
    enum class ShipType {
        Pinnace, Sloop, Brig, Barc, Fluyt, Corvette, Frigate, Galleon, LAST
    };

    static std::unique_ptr<Ship> CreateShip(ShipType type, 
        std::string name, Player::Delegate* delegate);

private:
    static size_t id_;
};

#endif  // SHIP_FACTORY_H