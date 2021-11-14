#pragma once
#include <string>


class Player
{
public:
	std::string name{};
	int wins{};
	int losses{};
	Player() {};
	~Player(){};



private:

};


Player playerOne{};
Player playerTwo{};