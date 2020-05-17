#ifndef GAME_H
#define GAME_H

#include <memory>

#include "CargoTypes.h"
#include "Command.h"
#include "GTime.h"
#include "Map.h"
#include "Player.h"
#include "Shipyard.h"

// Class is resposible for game content.
// Player need to gain final_goal_ money in specified days to win
class Game {
public:
	enum class Action { Travel = 1, Sell = 2,
					 Buy = 3, PrintCargo = 4 ,
					 BuyShip = 5, SellShip = 6};

	Game(size_t money, size_t days, size_t final_goal);
	~Game() = default;
    void StartGame();

private:
    bool CheckWinCondition() const;
	bool CheckLooseCodition() const;
	void PrintMenu();
	void PrintOptions();
	void PrintWinScreen();
	void PrintLooseScreen();
	void MakeAction(Action choice);

    size_t money_;
    size_t days_;
    size_t final_goal_;
	std::unique_ptr<CargoTypes> cargo_types_;
	std::unique_ptr<Time> time_;
    std::unique_ptr<Map> map_;
	std::unique_ptr<Player> player_;
	std::unique_ptr<Shipyard> shipyard_;
	std::unique_ptr<Command> travel_command_;
	std::unique_ptr<Command> sell_command_;
	std::unique_ptr<Command> buy_command_;
	std::unique_ptr<Command> print_cargo_command_;
	std::unique_ptr<Command> buy_ship_command_;
	std::unique_ptr<Command> sell_ship_command_;
};

#endif // GAME_H