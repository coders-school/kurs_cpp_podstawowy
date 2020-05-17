#include "Command.h"

#include <chrono>
#include <iostream>
#include <thread>

#include "Map.h"
#include "Player.h"
#include "Shipyard.h"
#include "Store.h"
#include "GTime.h"

using namespace std::chrono_literals;

const std::string dash(80, '_');

Travel::Travel(Map* map, Time* time): map_(map), time_(time) {}

void Travel::execute(Player* player) {
    while (true) {
        std::cout << dash << "\n" << *map_;
        std::cout << "\nChoose destination: (type 0 0 to exit)";
        size_t x, y;
        std::cin >> x >> y;
        if (x == 0 && y == 0)
            return;
        Island* island = map_->GetIsland(Island::Coordinates(x, y));
        if (island != nullptr) {
            const size_t distance = map_->GetDistanceToIsland(island);
            map_->Travel(island);
            const size_t player_speed = player->GetSpeed();
            // Always round up travel_time
            const size_t travel_time = (distance + player_speed - 1) / player_speed;
            std::cout << "travel time: " << travel_time << "\n";
            char answer = 'N';
            while (true) {
                std::cout << "Are you sure to continue? (Y/n): ";
                std::cin >> answer;
                if (std::tolower(answer) == 'n')
                    return;
                else if (std::tolower(answer) == 'y')
                    break;
                std::cin.clear();
                std::cout << "Wrong answer!\n";
            }	
            for (size_t i = 0; i < travel_time; ++i) {
                ++*time_;
            }
            break;
        }
        std::cout << "\nWrong desination!\n";
    }
}

Sell::Sell(Map* map): map_(map) {}

void Sell::execute(Player* player) {
    while (true) {
        // Player want to see cargo, to choose which want to sell
        player->PrintCargo();
        auto* store = map_->GetCurrentPosition()->GetStore();
        std::cout << "\n" << *store << "\n";
        std::cout << "(type 0 0 to exit) Select product (number) and quantity: ";
        size_t quantity {};
        std::string product;
        std::cin >> product >> quantity;
        if (quantity == 0 && product == "0")
            return;
        const Cargo* cargo = store->GetCargo(product);
        if (!cargo) {
            std::cout << "Wrong name of cargo!\n";
            std::this_thread::sleep_for(2s);
            continue;
        }

        char answer = 'N';
        while (true) {
            std::cout << "Price is: " <<  store->GetCargoSellPrice(cargo, quantity) 
                        << " Are you sure to continue? (Y/n): ";
            std::cin >> answer;
            if (std::tolower(answer) == 'n')
                return;
            else if (std::tolower(answer) == 'y')
                break;
            std::cin.clear();
            std::cout << "Wrong answer!\n";
        }	

        switch (store->Sell(cargo, quantity, player)) {
        case Store::Response::done:
            std::cout << "Sell " << quantity << " " << product << '\n';
            std::this_thread::sleep_for(2s);
            return;
            break;
        case Store::Response::lack_of_space:
            std::cout << "There is no enough space in stores!\n";
            std::this_thread::sleep_for(2s);
            break;
        default:
            break;
        }
    }
}

Buy::Buy(Map* map): map_(map) {}

void Buy::execute(Player* player) {
    while (true) {
        auto* store = map_->GetCurrentPosition()->GetStore();
        std::cout << "\n" << *store << "\n";
        std::cout << "(type 0 0 to exit) Select product (name) and quantity: ";
        size_t quantity {};
        std::string product;
        std::cin >> product >> quantity;
        if (quantity == 0 && product == "0")
            return;
        const Cargo* cargo = store->GetCargo(product);
        if (!cargo) {
            std::cout << "Wrong name of cargo!\n";
            std::this_thread::sleep_for(2s);
            continue;
        }

        char answer = 'N';
        while (true) {
            std::cout << "Price is: " <<  store->GetCargoBuyPrice(cargo, quantity) 
                    << " Are you sure to continue? (Y/n): ";
            std::cin >> answer;
            if (std::tolower(answer) == 'n')
                return;
            else if (std::tolower(answer) == 'y')
                break;
            std::cin.clear();
            std::cout << "Wrong answer!\n";
        }	

        switch (store->Buy(cargo, quantity, player)) {
        case Store::Response::done:
            std::cout << "Buy " << quantity << " " << product << '\n';
            std::this_thread::sleep_for(2s);
            return;
            break;
        case Store::Response::lack_of_cargo:
            std::cout << "There is no enough cargo to buy!\n";
            std::this_thread::sleep_for(2s);
            break;
        case Store::Response::lack_of_money:
            std::cout << "You dont have enough money to buy cargo!\n";
            std::this_thread::sleep_for(2s);
            break;
        case Store::Response::lack_of_space:
            std::cout << "You dont have enough space to store cargo\n";
            std::this_thread::sleep_for(2s);
            break;
        default:
            break;
        }
    }
}

void PrintCargo::execute(Player* player) {
		player->PrintCargo();
}

BuyShip::BuyShip(Shipyard* shipyard): shipyard_(shipyard) {}

void BuyShip::execute(Player* player) {
    while (true) {
        shipyard_->PrintShipsToBuild();
        std::cout << "Select ship type and name (type 0 0 to exit): ";
        std::string ship_type, ship_name;
        std::cin >> ship_type >> ship_name;
        if (ship_type ==  "0" && ship_name == "0")
            return;

        char answer = 'N';
        while (true) {
            std::cout << "Are you sure to buy this ship? (Y/n): ";
            std::cin >> answer;
            if (std::tolower(answer) == 'n')
                return;
            else if (std::tolower(answer) == 'y')
                break;
            std::cin.clear();
            std::cout << "Wrong answer!\n";
        }	

        switch (shipyard_->BuyShip(ship_type, ship_name, player)) {
        case Shipyard::Response::done:
            std::cout << "Buy: " << ship_type << " named: " << ship_name << '\n';
            std::this_thread::sleep_for(2s);
            return;
            break;
        case Shipyard::Response::lack_of_money:
            std::cout << "You dont have enough money to buy ship!\n";
            std::this_thread::sleep_for(2s);
            break;
        case Shipyard::Response::lack_of_space:
            std::cout << "You dont have enough space to hold another ship\n";
            std::this_thread::sleep_for(2s);
            break;
        case Shipyard::Response::wrong_type_of_ship:
            std::cout << "Wrong type of ship\n";
            std::this_thread::sleep_for(2s);
            break;
        default:
            break;
        }
    }
}

SellShip::SellShip(Shipyard* shipyard): shipyard_(shipyard) {}

void SellShip::execute(Player* player) {
    while (true) {
        player->PrintShips();
        std::cout << "Select ship id (type 0 to exit): ";
        int id {0};
        std::cin >> id;
        if (!id)
            return;

        char answer = 'N';
        while (true != 'y') {
            std::cout << "Are you sure to sell this ship for (80% of his price)?\n"
                    << "You will also lost all cargo hold on this ship. (Y/n): ";
            std::cin >> answer;
            if (std::tolower(answer) == 'n')
                return;
            else if (std::tolower(answer) == 'y')
                break;
            std::cin.clear();
            std::cout << "Wrong answer!\n";
        }	

        switch (shipyard_->SellShip(id, player)) {
        case Shipyard::Response::done:
            std::cout << "Ship sold!\n";
            std::this_thread::sleep_for(2s);
            return;
            break;
        case Shipyard::Response::last_ship_cant_be_sold:
            std::cout << "You can't sell last ship!\n";
            std::this_thread::sleep_for(2s);
            break;
        default:
            break;
        }
    }
}