#pragma once
#include "Hand.h"
#include "Deck.h"

class RoyalFlush:public Hand
{
	void swap(Card& card1, Card& card2);
	void sortCards(Card* allCards, int size);
	bool evaluate(Card* communityCards, Card* playerCards);
};

