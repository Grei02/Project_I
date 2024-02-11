#include "Bet.h"

Bet::Bet(Player _bettor, int _amount)
{
	bettor = _bettor;
	amount = _amount;
}

Player Bet::getBettor()
{
	return bettor;
}

int Bet::getAmount()
{
	return amount;
}
