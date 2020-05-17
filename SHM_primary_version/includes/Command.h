#ifndef COMMAND_H
#define COMMAND_H

class Map;
class Player;
class Shipyard;
class Time;

class Command {
public:
	~Command() = default;
	virtual void execute(Player* player) = 0;
};

class Travel : public Command {
public:
	Travel(Map* map, Time* time);
	~Travel() = default;
	void execute(Player* player) override;
private:
	Map* map_;
	Time* time_;
};

class Sell : public Command {
public:
	Sell(Map* map);
	~Sell() = default;
	void execute(Player* player) override;

private:
	Map* map_;
};

class Buy : public Command {
public:
	Buy(Map* map);
	~Buy() = default;
	void execute(Player* player) override;
private:
	Map* map_;
};

class PrintCargo : public Command {
public:
	~PrintCargo() = default;
	void execute(Player* player) override;
};

class SellShip : public Command {
public:
    SellShip(Shipyard* shipyard);
	~SellShip() = default;
	void execute(Player* player) override;

private:
    Shipyard* shipyard_;
};

class BuyShip : public Command {
public:
    BuyShip(Shipyard* shipyard);
	~BuyShip() = default;
	void execute(Player* player) override;

private:
    Shipyard* shipyard_;
};

#endif // COMMAND_H