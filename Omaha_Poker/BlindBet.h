#pragma once
#include "Bet.h"
class BlindBet
{
private:
	Player* players;
	Bet littleBet;
	Bet bigBet;
public:
	BlindBet(Player* _players) : players(_players) {}
<<<<<<< HEAD
	void asignarCiegas(int indiceDealer, int maxOfPlayers);
=======
	void asignarCiegas(int indiceDealer,int maxOfPlayers);
>>>>>>> b7c45bf5a10754f9f44e291d860ac0d0f0b7326f
	Bet getLittleBet();
	Bet getBigBet();
};

