#pragma once
#include "Card.h"

const int  maxHandCards = 4;
class Hand
{
public:
	Card* playerHand[maxHandCards];
	Hand();
	~Hand();
	virtual bool evaluate(Card* commutyCards, Card* playerCards) = 0;
};
