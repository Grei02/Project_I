#pragma once
#include "Player.h"
class Bet
{
private:
	Player bettor;
	int amount;
public:
	Bet(){}
	Bet(Player _bettor, int _amount);
	Player getBettor();
	int getAmount();

};

