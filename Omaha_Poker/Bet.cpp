#include "Bet.h"
<<<<<<< HEAD
=======

>>>>>>> b7c45bf5a10754f9f44e291d860ac0d0f0b7326f
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
