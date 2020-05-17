#include <iostream>

#include "Game.h"

constexpr size_t start_money = 1'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000; 

int main() {
    Game game(start_money, game_days, final_goal);
    game.StartGame();

    return 0;
}