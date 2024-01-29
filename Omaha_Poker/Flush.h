#pragma once
#include "Hand.h"

class Flush :public Hand
{
	bool evaluate(Card* communityCards, Card* playerCards);
};

