#ifndef GAME_H
#define GAME_H

#include <memory>

#include "Map.h"
#include "Player.h"
#include "GTime.h"

// Class is resposible for game content.
// Player need to gain final_goal_ money in specified days to win
class Game {
public:
	enum class Action { Travel = 1, Sell = 2, Buy = 3, PrintCargo = 4 };

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
	void Travel();
	void Buy();
	void Sell();
	void PrintCargo();

    size_t money_;
    size_t days_;
    size_t final_goal_;
	bool end_day_{ false };
	std::unique_ptr<Time> time_;
    std::unique_ptr<Map> map_;
	std::unique_ptr<Player> player_;
};

#endif // GAME_H