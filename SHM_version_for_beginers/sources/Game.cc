#include "Game.h"

#include <chrono>
#include <string>
#include <thread>

#include "Cargo.h"
#include "Island.h"
#include "Store.h"

using namespace std::chrono_literals;

const std::string dash(80, '_');

Game::Game(size_t money, size_t days, size_t final_goal) :
	money_(money),
	days_(days),
	final_goal_(final_goal),
	time_(std::make_unique<Time>()),
	map_(std::make_unique<Map>(time_.get())),
	player_(std::make_unique<Player>(money, time_.get())) {
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
		if (end_day_) {
			end_day_ = false;
		}
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
		<< "4) Check Cargo\n" << "0) Exit\n\n" << "Choice: ";
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
		Travel();
		break;
	case Action::Sell:
		Sell();
		break;
	case Action::Buy:
		Buy();
		break;
	case Action::PrintCargo:
		PrintCargo();
		system("pause");
		break;
	default:
		std::cout << "Wrong option!\n";
		std::this_thread::sleep_for(2s);
		break;
	}
}
	
void Game::Travel() {
	while (true) {
		std::cout << dash << "\n" << *map_;
		std::cout << "\nChoose destination: ";
		size_t x, y;
		std::cin >> x >> y;
		Island* island = map_->GetIsland(Island::Coordinates(x, y));
		if (island != nullptr) {
			const size_t distance = map_->GetDistanceToIsland(island);
			map_->Travel(island);
			const size_t player_speed = player_->GetSpeed();
			// Always round up travel_time
			const size_t travel_time = (distance + player_speed - 1) / player_speed;
			std::cout << "travel time: " << travel_time << "\n";
			for (size_t i = 0; i < travel_time; ++i) {
				++*time_;
			}
			end_day_ = true;
			break;
		}
		std::cout << "\nWrong desination!\n";
	}
}

void Game::Buy() {
	while (true) {
		auto* store = map_->GetCurrentPosition()->GetStore();
		std::cout << "\n" << *store << "\n";
		std::cout << "(type 0 0 to exit) Select product (number) and quantity: ";
		size_t product, quantity;
		std::cin >> product >> quantity;
		if (product == 0)
			return;
		Cargo* cargo = store->GetCargo(--product); // Index from 0
		// Copy name, beacuse when whole cargo will be sell, pointer will be deleted
		std::string name = cargo->GetName();
		const Store::Response response = store->Buy(cargo, quantity, player_.get());
		switch (response) {
		case Store::Response::done:
			std::cout << "Buy " << quantity << " " << name << '\n';
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

void Game::Sell() {
	while (true) {
		// Player want to see cargo, to choose which want to sell
		PrintCargo(); 
		auto* store = map_->GetCurrentPosition()->GetStore();
		std::cout << "\n" << *store << "\n";
		std::cout << "(type 0 0 to exit) Select product (number) and quantity: ";
		size_t product, quantity;
		std::cin >> product >> quantity;
		if (product == 0)
			return;
		Cargo* cargo = player_->GetCargo(--product);
		std::cout << "Do you want to sell " << quantity << " " << cargo->GetName() 
			<< " for: " << store->GetCargoSellPrice(cargo, quantity)
			<< "? (Y|y)\n";
		char answ;
		std::cin >> answ;
		if (answ != 'Y' && answ != 'y')
			break;
		// Copy name, beacuse when whole cargo will be sell, pointer will be deleted
		std::string name = cargo->GetName();
		const Store::Response response = store->Sell(cargo, quantity, player_.get());
		switch (response) {
		case Store::Response::done:
			std::cout << "Sell " << quantity << " " << name << '\n';
			std::this_thread::sleep_for(2s);
			return;
			break;
		case Store::Response::lack_of_cargo:
			std::cout << "There is no enough cargo to sell!\n";
			std::this_thread::sleep_for(2s);
			break;
		case Store::Response::lack_of_space:
			std::cout << "There is no enough space in storess!\n";
			std::this_thread::sleep_for(2s);
			break;
		default:
			break;
		}
	}
}

void Game::PrintCargo() {
	player_->PrintCargo();
}