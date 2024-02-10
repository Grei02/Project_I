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
	void asignarCiegas(int indiceDealer,int maxOfPlayers);
	Bet getLittleBet();
	Bet getBigBet();
};

