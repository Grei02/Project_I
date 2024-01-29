#pragma once
#include "Hand.h"

class DoublePair:public Hand 
{
	bool evaluate(Card* communityCards, Card* playerCards);
};

