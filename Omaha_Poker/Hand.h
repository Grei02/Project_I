#pragma once
#include "Card.h"

const int maxHandCards = 4;

class Hand
{
public:
	Card* playerHand[maxHandCards];
	Hand();
	~Hand();
};
