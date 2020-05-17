#include "Game.h"

#include <chrono>
#include <string>
#include <thread>

#include "Cargo.h"
#include "CargoTypeServiceLocator.h"
#include "Island.h"
#include "Store.h"
#include "TimeServiceLocator.h"

using namespace std::chrono_literals;

const std::string dash(80, '_');

Game::Game(size_t money, size_t days, size_t final_goal) :
	money_(money),
	days_(days),
	final_goal_(final_goal),
	cargo_types_(std::make_unique<CargoTypes>()),
	time_(std::make_unique<Time>()) {

	TimeServiceLocator::Provide(time_.get());
	CargoTypeServiceLocator::Provide(cargo_types_.get());
	map_ = std::make_unique<Map>();
	player_ = std::make_unique<Player>(money);
	shipyard_ = std::make_unique<Shipyard>();
	travel_command_ = std::make_unique<Travel>(map_.get(), time_.get());
	sell_command_ = std::make_unique<Sell>(map_.get());
	buy_command_ = std::make_unique<Buy>(map_.get());
	print_cargo_command_ = std::make_unique<PrintCargo>();
	buy_ship_command_ = std::make_unique<BuyShip>(shipyard_.get());
	sell_ship_command_ = std::make_unique<SellShip>(shipyard_.get());
}

void Game::StartGame() {
	std::cout << "Welcome in game SHM, you have: " << days_
		<< " days, to gain: " << money_ << " GOOD LUCK!\n\n";

	while (days_ > time_->GetElpasedTime()) {
		if (CheckWinCondition()) {
			PrintWinScreen();
			return;
		} else if (CheckLooseCodition()) {
			break;
		}
		std::cout << dash << "\n";
		PrintMenu();
		PrintOptions();
		size_t action;
		std::cin.clear();
		std::cin >> action;
		if (action == 0)
			break;
		MakeAction(static_cast<Action>(action));
		system("cls");
	}
	PrintLooseScreen();
}

bool Game::CheckWinCondition() const {
	return player_->GetMoney() >= final_goal_;
}

bool Game::CheckLooseCodition() const {
	return player_->GetMoney() == SIZE_MAX;
}

void Game::PrintMenu() {
	std::cout << "Money: " << player_->GetMoney() 
		<< " Day: " << time_->GetElpasedTime()
		<< " Days left: " << days_ - time_->GetElpasedTime()
		<< " Current position: " 
		<< map_->GetCurrentPosition()->GetCoordinates() << "\n";
}

void Game::PrintOptions() {
	std::cout << "\n" << "1) Travel\n" << "2) Sell\n" << "3) Buy\n"
		<< "4) Check cargo\n" << "5) Buy ship\n" << "6) Sell Ship\n" 
		<< "0) Exit\n\n" << "Choice: ";
}

void Game::PrintWinScreen() {
	system("cls");
	std::cout << "CONGRATULATIUON! You earn: " << player_->GetMoney()
		<< " money in: " << time_->GetElpasedTime() << " days";
	std::this_thread::sleep_for(5s);
}

void Game::PrintLooseScreen() {
	system("cls");
	std::cout << "GAME OVER! You earn: " << player_->GetMoney()
		<< " money in: " << time_->GetElpasedTime() << " days";
	std::this_thread::sleep_for(5s);
}

void Game::MakeAction(Action choice) {
	switch (choice) {
	case Action::Travel:
		travel_command_->execute(player_.get());
		break;
	case Action::Sell:
		sell_command_->execute(player_.get());
		break;
	case Action::Buy:
		buy_command_->execute(player_.get());
		break;
	case Action::PrintCargo:
		print_cargo_command_->execute(player_.get());
		system("pause");
		break;
	case Action::SellShip:
		sell_ship_command_->execute(player_.get());
		break;
	case Action::BuyShip:
		buy_ship_command_->execute(player_.get());
		break;
	default:
		std::cout << "Wrong option!\n";
		std::this_thread::sleep_for(2s);
		break;
	}
}
