#pragma once
#include "Player.h"
class Bet
{
private:
	Player bettor;
	int amount;
public:
	Bet() {}
	Bet(const Player& _bettor, int _amount ): bettor(_bettor), amount(_amount) {}
	Player getBettor();
	int getAmount();

};